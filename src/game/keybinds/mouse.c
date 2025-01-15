/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:15:41 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/15 12:09:05 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	handle_pressed_mouse_event(int key, t_mlx *mlx)
{
	t_game	*game;
	t_vec2	coords;
	int		x;
	int		y;

	x = 0;
	y = 0;
	(void)mlx;
	game = get_game_instance();
	if (!game || !game->mlx || !game->mlx->mlx || !game->mlx->win)
		return ;
	mlx_mouse_get_pos(game->mlx->mlx, game->mlx->win, &x, &y);
	if (key == 1)
		game->last_mouse_location = (t_vec2){x, y};
	else if (key == 3 && game->entities)
	{
		coords = get_to_tile_coord(game, x + game->camera_offsets.x, y
				+ game->camera_offsets.y);
		if (is_same_position(game->entities->pos, coords))
			return ;
		if (game->entities->path_to_follow)
			free_path_nodes(game->entities->path_to_follow);
		game->entities->path_to_follow = find_path(game->entities->pos, coords);
	}
}

void	handle_release_mouse_event(int x, int y, t_mlx *mlx)
{
	t_game	*game;

	game = get_game_instance();
	(void)y;
	(void)x;
	(void)mlx;
	if (!game || !game->init || !game->mlx || !game->mlx->win
		|| !game->mlx->mlx)
		return ;
	game->last_mouse_location = (t_vec2){0, 0};
}

void	handle_mouse_motion_event(int x, int y, t_mlx *mlx)
{
	t_vec2	vec2;
	t_game	*game;

	game = get_game_instance();
	(void)y;
	(void)x;
	(void)mlx;
	if (!game || !game->init || !game->mlx || !game->mlx->win
		|| !game->mlx->mlx)
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
