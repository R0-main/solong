/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighbors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:12:34 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/10 10:33:55 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "path_finding.h"
#include "path_finding_utils.h"

bool	is_wall(t_map *map, t_vec2 pos)
{
	t_vec2	map_max;

	map_max = (t_vec2){map->witdh - 1, map->height - 1};
	return (is_between_zero_and(pos, map_max)
		&& map->buffer[pos.y][pos.x] == '1');
}

void	set_neightbors(t_node **first, t_vec2 pos, t_node *node, t_vec2 to)
{
	t_vec2	vec;
	t_game	*game;

	game = get_game_instance();
	if (!game)
		return ;
	vec = (t_vec2){pos.x, pos.y - 1};
	if (is_between(vec, pos, to) && !is_wall(game->map, vec) && !node->up)
		node->up = create_node_tree(first, vec, to);
	vec = (t_vec2){pos.x, pos.y + 1};
	if (is_between(vec, pos, to) && !is_wall(game->map, vec) && !node->down)
		node->down = create_node_tree(first, vec, to);
	vec = (t_vec2){pos.x + 1, pos.y};
	if (is_between(vec, pos, to) && !is_wall(game->map, vec) && !node->right)
		node->right = create_node_tree(first, vec, to);
	vec = (t_vec2){pos.x - 1, pos.y};
	if (is_between(vec, pos, to) && !is_wall(game->map, vec) && !node->left)
		node->left = create_node_tree(first, vec, to);
}
