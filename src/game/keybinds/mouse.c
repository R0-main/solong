/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:15:41 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/10 14:06:00 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	handle_pressed_mouse_event(int key, t_mlx *mlx)
{
	t_game	*game;
	int		x;
	int		y;

	x = 0;
	y = 0;
	game = get_game_instance();
	if (!game || !game->mlx || !game->mlx->mlx || !game->mlx->win)
		return ;
	mlx_mouse_get_pos(game->mlx->mlx, game->mlx->win, &x, &y);
	game->last_mouse_location = (t_vec2){x, y};
}

void	handle_release_mouse_event(int x, int y, t_mlx *mlx)
{
	t_game	*game;

	game = get_game_instance();
	if (!game)
		return ;
	game->last_mouse_location = (t_vec2){0, 0};
}

void	handle_mouse_motion_event(int x, int y, t_mlx *mlx)
{
	t_vec2	vec2;
	t_game	*game;

	game = get_game_instance();
	if (!game)
		return ;
	if (!game->last_mouse_location.x || !game->last_mouse_location.y)
		return ;
	vec2 = (t_vec2){game->last_mouse_location.x - x, game->last_mouse_location.y
		- y};
	if (game->camera_offsets.x + vec2.x + WIDTH < game->map->map_img->width
		&& game->camera_offsets.x + vec2.x > 0)
		game->camera_offsets.x += vec2.x;
	if (game->camera_offsets.y + vec2.y + HEIGHT < game->map->map_img->height
		&& game->camera_offsets.y + vec2.y > 0)
		game->camera_offsets.y += vec2.y;
	game->last_mouse_location = (t_vec2){x, y};
}
