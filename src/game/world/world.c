/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:05:13 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/06 10:05:27 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_coordinates	get_to_world_coord(int x, int y)
{
	t_coordinates	coords;

	coords.x = (x * TILE_X * 0.5) + (y * -0.5 * TILE_X);
	coords.y = (x * TILE_Y * 0.25) + (y * 0.25) * TILE_Y;
	coords.x *= 2;
	coords.y *= 2;
	// coords.x += (w * TILE_X) - TILE_X * 0.5;
	return (coords);
}
