/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:35:40 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 17:02:36 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game.h"
#include "mlx_wrapper.h"

#define OFFSET 100

void	on_key_pressed(int key)
{
	t_game		*game;
	t_vec2		vec;
	t_texture	texture;
	t_direction	direction;

	game = get_game_instance();
	if (!game)
		return ;
	vec = game->entities->pos;
	if (!game->entities || game->entities->type != PLAYER_TYPE)
		return ;
	if (key == W_KEY || key == UP_ARROW_KEY)
	{
		direction = UP;
		vec.y -= 1;
	}
	else if (key == S_KEY || key == DOWN_ARROW_KEY)
	{
		direction = DOWN;
		vec.y += 1;
	}
	else if (key == A_KEY || key == LEFT_ARROW_KEY)
	{
		direction = LEFT;
		vec.x -= 1;
	}
	else if (key == D_KEY || key == RIGHT_ARROW_KEY)
	{
		direction = RIGHT;
		vec.x += 1;
	}
	if (!is_wall(game->map, vec) && !game->entities->path_to_follow
		&& !is_same_position(vec, game->entities->pos))
	{
		game->steps_made += 1;
		game->entities->pos = vec;
		game->entities->last_direction = direction;
	}
	printf("x : %d | y : %d h : %d\n", game->camera_offsets.x,
		game->camera_offsets.y, game->map->height);
}

int	handle_key(int keycode, t_mlx *mlx)
{
	if (!mlx || !mlx->mlx || !mlx->win)
		return (1);
	if (keycode == 65307 || keycode == -16778664)
	{
		mlx_loop_end(mlx->mlx);
	}
	on_key_pressed(keycode);
	ft_printf("pressed : %d\n", keycode);
	return (0);
}
