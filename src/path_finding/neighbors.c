/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighbors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:12:34 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/10 16:54:29 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "path_finding.h"
#include "path_finding_utils.h"

bool	is_wall(t_map *map, t_vec2 pos)
{
	t_vec2	map_max;

	map_max = (t_vec2){map->width, map->height};
	return (is_between_zero_and(pos, map_max)
		&& map->buffer[pos.y][pos.x] == WALL);
}

void	set_neightbors(t_node **first, t_vec2 from, t_node *node, t_vec2 to)
{
	t_vec2	vec;
	t_map	*map;

	map = get_map();
	if (!map)
		return ;
	vec = (t_vec2){node->pos.x, node->pos.y - 1};
	if (!is_wall(map, vec) && !node->neighbors[UP])
		node->neighbors[UP] = create_node_tree(first, vec, from, to);
	vec = (t_vec2){node->pos.x, node->pos.y + 1};
	if (!is_wall(map, vec) && !node->neighbors[DOWN])
		node->neighbors[DOWN] = create_node_tree(first, vec, from, to);
	vec = (t_vec2){node->pos.x + 1, node->pos.y};
	if (!is_wall(map, vec) && !node->neighbors[RIGHT])
		node->neighbors[RIGHT] = create_node_tree(first, vec, from, to);
	vec = (t_vec2){node->pos.x - 1, node->pos.y};
	if (!is_wall(map, vec) && !node->neighbors[LEFT])
		node->neighbors[LEFT] = create_node_tree(first, vec, from, to);
}
