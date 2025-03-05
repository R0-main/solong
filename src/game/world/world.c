/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:05:13 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/15 12:00:56 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_vec2	get_to_world_coord(int x, int y)
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

	x /= TILE_X;
	y /= TILE_Y;
	x -= get_min_x(game) / TILE_X;
	coords.x = (2.0 * y + x) * 0.5;
	coords.y = (2.0 * y - x) * 0.5;
	return (coords);
}
