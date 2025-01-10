/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighbors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:12:34 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/10 09:22:54 by rguigneb         ###   ########.fr       */
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

void	set_neightbors(t_map *map, t_vec2 pos, t_node *first, t_node *node,
		t_vec2 to, long index)
{
	t_vec2	up;
	t_vec2	down;
	t_vec2	right;
	t_vec2	left;

	up = (t_vec2){pos.x, pos.y - 1};
	if (is_between(up, pos, to) && !is_wall(map, up) && !node->up)
		create_node_tree(&first, &node->up, up, to, index);
	down = (t_vec2){pos.x, pos.y + 1};
	if (is_between(down, pos, to) && !is_wall(map, down) && !node->down)
		create_node_tree(&first, &node->down, down, to, index);
	right = (t_vec2){pos.x + 1, pos.y};
	if (is_between(right, pos, to) && !is_wall(map, right) && !node->right)
		create_node_tree(&first, &node->right, right, to, index);
	left = (t_vec2){pos.x - 1, pos.y};
	if (is_between(left, pos, to) && !is_wall(map, left) && !node->left)
		create_node_tree(&first, &node->left, left, to, index);
}
