/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighbors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:12:34 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 08:34:56 by rguigneb         ###   ########.fr       */
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

void	foreach_neighbor(t_node **first, t_node **current, t_vec2 to,
		unsigned long distance_from_origin)
{
	int		y;
	t_map	*map;
	t_node	*neighbor;
	t_vec2	vec;

	map = get_map();
	y = -1;
	while (++y < 4)
	{
		vec = (*current)->neighbors[y];
		neighbor = create_node((*first), vec, to, distance_from_origin);
		if (!is_wall(map, vec) && !already_a_node((*first), neighbor->pos)
			&& \
			(*current)->distance_from_origin <= neighbor->distance_from_origin)
		{
			neighbor->prev = (*current);
			neighbor->prev_direction = y;
			neighbor->f_score = neighbor->cost;
			add_to_list((*first), neighbor);
		}
		else
			free(neighbor);
	}
}