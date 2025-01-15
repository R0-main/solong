/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edges.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:01:53 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/15 11:58:05 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	get_max_x(t_game *game)
{
	return (get_to_world_coord(game->map->width, 0).x + get_min_x(game));
}

int	get_max_y(t_game *game)
{
	return (get_to_world_coord(game->map->width, game->map->height).y);
}

int	get_min_y(void)
{
	t_vec2	pos;

	pos = get_to_world_coord(1, 1);
	return (abs(pos.y));
}

int	get_min_x(t_game *game)
{
	t_vec2	pos;

	pos = get_to_world_coord(1, game->map->height);
	if (pos.x > 0)
		return (0);
	return (abs(pos.x) - TILE_X / 2);
}
