/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 08:35:02 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/09 12:54:58 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "limits.h"
#include <stdint.h>

typedef enum e_directions
{
	UP,
	DOWN,
	RIGHT,
	LEFT
}					t_direction;

typedef struct s_path
{
	t_direction		direction;
	struct s_path	*next;
}					t_path;

typedef struct s_node
{
	int				path_cost;
	bool			inspected;
	bool			is_taget;
	struct s_node	*prev;
	struct s_node	*up;
	struct s_node	*down;
	struct s_node	*right;
	struct s_node	*left;
}					t_node;

#define S_NODE_OFFSET sizeof(t_node) - sizeof(t_node *) * 4

void				create_node_tree(t_node **first, t_node **current,
						t_vec2 pos, t_vec2 to, long index);

bool	is_on_player(char **buffer, t_vec2 pos)
{
	if (!buffer || !buffer[pos.y] || !buffer[pos.y][pos.x])
		return (false);
	else if (buffer[pos.y][pos.x] == 'P')
		return (true);
	return (false);
}

void	free_path_nodes(t_path *first)
{
	if (first)
	{
		free_path_nodes(first->next);
		free(first);
	}
}

t_path	*create_path_node(t_path *first)
{
	t_path	*path;

	path = (t_node *)malloc(sizeof(t_node));
	if (!path)
	{
		free_path_nodes(first);
		exit_error("failed to create a path node");
		return (NULL);
	}
	path->direction = 0;
	path->next = NULL;
	return (path);
}

void	create_node(t_node *first, t_node **node)
{
	*node = (t_node *)malloc(sizeof(t_node));
	if (!*node)
	{
		exit_error("failed to create a node");
		return ;
	}
	(*node)->down = NULL;
	(*node)->up = NULL;
	(*node)->left = NULL;
	(*node)->right = NULL;
	(*node)->path_cost = 0;
	(*node)->inspected = false;
	(*node)->is_taget = false;
}

void	free_nodes(t_node *first)
{
	if (!first)
		return ;
	free_nodes(first->down);
	free_nodes(first->up);
	free_nodes(first->left);
	free_nodes(first->right);
	if (first)
		free(first);
}

void	*error(t_node *first)
{
	free_nodes(first);
	exit_error("node creation failed in the pathfinding");
	return (NULL);
}

bool	is_wall(t_map *map, t_vec2 pos)
{
	t_vec2	map_max;

	map_max = (t_vec2){map->witdh - 1, map->height - 1};
	return (is_between_zero_and(pos, map_max)
		&& map->buffer[pos.y][pos.x] == '1');
}

void	set_neightbors(t_map *map, t_vec2 pos, t_node *first, t_node *node,
		t_vec2 to, long index)
{
	t_vec2	up;
	t_vec2	down;
	t_vec2	right;
	t_vec2	left;

	up = (t_vec2){pos.y - 1, pos.x};
	if (is_between(up, pos, to) && !is_wall(map, up) && !node->up)
		create_node_tree(&first, &node->up, up, to, index);
	down = (t_vec2){pos.y + 1, pos.x};
	if (is_between(down, pos, to) && !is_wall(map, down) && !node->down)
		create_node_tree(&first, &node->down, down, to, index);
	right = (t_vec2){pos.y, pos.x + 1};
	if (is_between(right, pos, to) && !is_wall(map, right) && !node->right)
		create_node_tree(&first, &node->right, right, to, index);
	left = (t_vec2){pos.y, pos.x - 1};
	if (is_between(left, pos, to) && !is_wall(map, left) && !node->left)
		create_node_tree(&first, &node->left, left, to, index);
}

void	create_node_tree(t_node **first, t_node **current, t_vec2 pos,
		t_vec2 to, long index)
{
	t_game	*game;
	t_vec2	max_map;

	if (*current)
		return ;
	game = get_game_instance();
	max_map = (t_vec2){game->map->witdh, game->map->height};
	if (!is_between_zero_and(pos, max_map))
		return ;
	create_node(*first, current);
	(*current)->path_cost = index;
	if (!*first)
		*first = *current;
	if (is_same_position(pos, to))
		return ;
	set_neightbors(game->map, pos, *first, *current, to, index - 1);
}

void	print_path(t_path *path)
{
	while (path->next)
	{
		if (path->direction == UP)
			printf("UP\n");
		if (path->direction == DOWN)
			printf("DOWN\n");
		if (path->direction == RIGHT)
			printf("RIGHT\n");
		if (path->direction == LEFT)
			printf("LEFT\n");
		path = path->next;
	}
}

t_direction	get_most_efficient(t_node *c)
{
	int			min;
	t_direction	i;
	t_direction	direction;
	t_node		*target;

	i = 0;
	while (i < LEFT - 1)
	{
		target = ((char *)c + S_NODE_OFFSET + (i * sizeof(t_node *)));
		if (target && !target->inspected && c->path_cost > min)
		{
			min = c->path_cost;
			direction = i;
		}
		i++;
	}
	return (direction);
}

void	path_backtracking(t_node *current)
{
	t_direction	direction;
	t_node		*next;

	if (current->is_taget)
		return ;
	direction = get_most_efficient(current);
	current->inspected = true;
	next = ((char *)current + S_NODE_OFFSET + direction * sizeof(t_node *));
	next->prev = current;
	path_backtracking(next);
}

void	find_path(t_vec2 pos, t_vec2 to)
{
	t_node	*first;
	t_node	*current;
	t_path	*path_to_follow_first;
	t_path	*path_to_follow;
	t_node	*last;
	long	min_path_cost;

	first = NULL;
	min_path_cost = 0;
	create_node_tree(&first, &first, pos, to, INT_MAX + 1);
	if (!first)
		return ;
	current = first;
	path_to_follow = create_path_node(path_to_follow);
	path_to_follow_first = path_to_follow;
	path_backtracking(current);
	print_path(path_to_follow_first);
	free_nodes(first);
	free_path_nodes(path_to_follow_first);
	// while ()
	// 	print_path(path_to_follow);
}

// t_node	*create_node_tree(t_vec2 from, t_vec2 to)
// {
// 	t_node	*first;
// 	t_node	*current;
// 	t_game	*game;

// 	game = get_game_instance();
// 	first = NULL;
// 	if (!is_between_zero_and(from, (t_vec2){game->map->witdh,
// 			game->map->height}))
// 		return (NULL);
// 	while (++from.y < game->map->height - 1)
// 	{
// 		from.x = from.x;
// 		while (++from.x < game->map->witdh)
// 		{
// 			current = create_node(first);
// 			set_neightbors(game->map, from, first, current);
// 			if (!first)
// 				first = current;
// 		}
// 	}
// 	return (first);
// }

bool	find_player(void)
{
	find_path((t_vec2){1, 1}, (t_vec2){3, 3});
}
