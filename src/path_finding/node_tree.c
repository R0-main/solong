/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:16:55 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/10 17:14:51 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "limits.h"
#include "path_finding.h"
#include "path_finding_utils.h"

void	set_node_cost(t_node *node, unsigned long i)
{
	printf("%d\n", i);
	if (!node || node->path_cost != 0)
		return ;
	node->path_cost = i;
	set_node_cost(node->neighbors[UP], i + 1);
	set_node_cost(node->neighbors[DOWN], i + 1);
	set_node_cost(node->neighbors[RIGHT], i + 1);
	set_node_cost(node->neighbors[LEFT], i + 1);
}

t_node	*create_node_tree(t_node **first, t_vec2 pos, t_vec2 from, t_vec2 to)
{
	t_node			*current;
	t_map			*map;
	t_vec2			max_map;
	static t_node	*array[8][53] = {};
	static int		i = 0;
	int				y;

	map = get_map();
	max_map = (t_vec2){map->width, map->height};
	if (!is_between_zero_and(pos, max_map))
		return (NULL);
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 53; x++)
		{
			array[y][x] = create_node(first, (t_vec2){x, y});
		}
	}
	current = create_node(first, pos);
	if (!*first)
		*first = current;
	if (array[pos.y][pos.x])
		return (array[pos.y][pos.x]);
	array[pos.y][pos.x] = current;
	set_neightbors(first, pos, current, to);
	if (is_same_position(pos, to))
	{
		printf("HERE \n");
		// printf("pos :  %d %d\n", pos.x, pos.y);
		// for (int i = 0; i < 500; i++)
		// {
		// 	printf("i : %d %d\n", array[i].x, array[i].y);
		// }
		set_node_cost(current, 0);
		current->is_taget = true;
		// for (int i = 0; i < 8; i++)
		// {
		// 	for (int x = 0; x < 53; x++)
		// 	{
		// 		if (array[i][x])
		// 			printf(" %d ", array[i][x]->path_cost);
		// 		else
		// 			printf(" - ");
		// 	}
		// 	printf("\n");
		// }
	}
	return (current);
}
