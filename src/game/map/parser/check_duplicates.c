/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:47:13 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 08:47:43 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	check_for_duplicate_point(t_map *map)
{
	int						x;
	int						y;
	t_map_needed_objects	objects;

	objects = (t_map_needed_objects){0, 0, 0};
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->buffer[y][x] == PLAYER)
				objects.player_count += 1;
			else if (map->buffer[y][x] == EXIT)
				objects.exit_count += 1;
			else if (map->buffer[y][x] == COLLECTIBLE)
				objects.collectible_count += 1;
		}
	}
	if (objects.player_count == 0 || objects.player_count > 1)
		exit_error(MAP_SPAWN_POINT_ERROR);
	if (objects.exit_count == 0 || objects.exit_count > 1)
		exit_error(MAP_EXIT_ERROR);
	if (objects.collectible_count == 0)
		exit_error(MAP_COLLECTIBLE_ERROR);
}