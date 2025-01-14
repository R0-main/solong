/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:50:34 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 16:19:31 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	setup_collectibles(t_map *map)
{
	t_vec2	coords;
	int		i;

	coords.y = -1;
	i = 0;
	while (++coords.y < map->height)
	{
		coords.x = -1;
		while (++coords.x < map->width)
		{
			if (map->buffer[coords.y][coords.x] == COLLECTIBLE)
			{
				if (i >= MAX_COLLECTIBLES)
					exit_error(MAP_MAX_COLLECTIBLE_ERROR);
				else
					map->collectibles_coords[i++] = coords;
			}
		}
	}
}

static void	setup_enemies(t_map *map)
{
	t_vec2	coords;
	int		i;

	coords.y = -1;
	i = 0;
	while (++coords.y < map->height)
	{
		coords.x = -1;
		while (++coords.x < map->width)
		{
			if (map->buffer[coords.y][coords.x] == ENEMY)
			{
				if (i >= MAX_ENEMIES)
					exit_error(MAP_MAX_ENEMY_ERROR);
				else
					map->enemies_coords[i++] = coords;
			}
		}
	}
}

void	setup_map_coords(t_map *map)
{
	t_vec2	coords;

	coords.y = -1;
	while (++coords.y < map->height)
	{
		coords.x = -1;
		while (++coords.x < map->width)
		{
			if (map->buffer[coords.y][coords.x] == PLAYER)
				map->player_spawnpoint = coords;
			else if (map->buffer[coords.y][coords.x] == EXIT)
				map->exit_coords = coords;
		}
	}
	setup_collectibles(map);
	setup_enemies(map);
}
