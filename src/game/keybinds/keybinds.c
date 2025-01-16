/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:35:40 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/16 13:04:58 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include "ft_printf.h"
#include "game.h"
#include "mlx_wrapper.h"

#define OFFSET 100

void	on_key_pressed(int key)
{
	t_game		*game;
	t_direction	direction;
	t_entity	*player;

	direction = -1;
	game = get_game_instance();
	if (!game || !game->init || !game->entities)
		return ;
	if (game->entities->type != PLAYER_TYPE)
		return ;
	player = game->entities;
	if (key == W_KEY || key == UP_ARROW_KEY)
		direction = UP;
	else if (key == S_KEY || key == DOWN_ARROW_KEY)
		direction = DOWN;
	else if (key == A_KEY || key == LEFT_ARROW_KEY)
		direction = LEFT;
	else if (key == D_KEY || key == RIGHT_ARROW_KEY)
		direction = RIGHT;
	if (!player->path_to_follow && move_entity(game, player, direction))
	{
		game->steps_made += 1;
		player->last_direction = direction;
	}
}

int	handle_key(int keycode, t_mlx *mlx)
{
	if (!mlx || !mlx->mlx || !mlx->win)
		return (1);
	if (keycode == ESC_KEY)
		mlx_loop_end(mlx->mlx);
	else
		on_key_pressed(keycode);
	return (0);
}
