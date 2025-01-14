/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:05:13 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 13:36:54 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_vec2	get_to_world_coord(t_game *game, int x, int y)
{
	t_vec2	coords;

	coords.x = (x * TILE_X * 0.5) + (y * -0.5 * TILE_X);
	coords.y = (x * TILE_Y * 0.25) + (y * 0.25) * TILE_Y;
	coords.x *= 2;
	coords.y *= 2;
	return (coords);
}

t_vec2	get_to_tile_coord(t_game *game, int x, int y)
{
	t_vec2	coords;
	int		temp_y;
	float	cartesianX;
	float	cartesianY;

	x /= TILE_X;
	y /= TILE_Y;
	x -= get_min_x(game) / TILE_X;
	coords.x = (2.0 * y + x) * 0.5;
	coords.y = (2.0 * y - x) * 0.5;
	return (coords);
}

int	get_max_x(t_game *game)
{
	return (get_to_world_coord(game, game->map->width, 0).x + get_min_x(game));
}

int	get_max_y(t_game *game)
{
	return (get_to_world_coord(game, game->map->width, game->map->height).y);
}

int	get_min_y(t_game *game)
{
	t_vec2	pos;

	pos = get_to_world_coord(game, 1, 1);
	return (abs(pos.y));
}

int	get_min_x(t_game *game)
{
	t_vec2	pos;

	pos = get_to_world_coord(game, 1, game->map->height);
	if (pos.x > 0)
		return (0);
	return (abs(pos.x) - TILE_X / 2);
}
