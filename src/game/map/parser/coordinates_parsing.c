/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:50:34 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 08:50:41 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	setup_map_coords(t_map *map)
{
	t_vec2	coords;
	int		collectible_index;

	coords.y = -1;
	collectible_index = 0;
	while (++coords.y < map->height)
	{
		coords.x = -1;
		while (++coords.x < map->width)
		{
			if (map->buffer[coords.y][coords.x] == PLAYER)
				map->player_spawnpoint = coords;
			else if (map->buffer[coords.y][coords.x] == EXIT)
				map->exit_coords = coords;
			else if (map->buffer[coords.y][coords.x] == COLLECTIBLE)
			{
				if (collectible_index >= MAX_COLLECTIBLE)
					exit_error(MAP_MAX_COLLECTIBLE_ERROR);
				else
					map->collectibles_coords[collectible_index++] = coords;
			}
		}
	}
}