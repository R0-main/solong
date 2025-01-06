/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:05:13 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/06 10:40:09 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_coordinates	get_to_world_coord(t_game *game, int x, int y)
{
	t_coordinates	coords;

	coords.x = (x * TILE_X * 0.5) + (y * -0.5 * TILE_X);
	coords.y = (x * TILE_Y * 0.25) + (y * 0.25) * TILE_Y;
	coords.x *= 2;
	coords.y *= 2;
	// coords.x += (w * TILE_X) - TILE_X * 0.5;
	return (coords);
}

int	get_max_x(t_game *game)
{
	t_coordinates	maxCoords;
	t_coordinates	maxCoords1;

	maxCoords = get_to_world_coord(game, game->map->witdh, 0);
	maxCoords1 = get_to_world_coord(game, 0, game->map->height);
	if (maxCoords1.x > 0)
		return (ft_abs(maxCoords1.x) - maxCoords.x);
	else
		return (maxCoords.x - maxCoords1.x);
}

int	get_max_y(t_game *game)
{
	t_coordinates	maxCoords;

	maxCoords = get_to_world_coord(game, game->map->witdh, game->map->height);
	return (maxCoords.y);
}

int	get_min_x(t_game *game)
{
	t_coordinates	maxCoords;

	maxCoords = get_to_world_coord(game, 1, game->map->height);
	return (ft_abs(maxCoords.x));
}
