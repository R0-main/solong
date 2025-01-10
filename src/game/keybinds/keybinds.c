/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:35:40 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/10 09:06:12 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx_wrapper.h"

#define OFFSET 100

void	on_key_pressed(int key)
{
	t_game	*game;

	game = get_game_instance();
	if (!game)
		return ;
	if (key == W_KEY || key == UP_ARROW_KEY)
	{
		game->camera_offsets.y += 100;
	}
	else if (key == S_KEY || key == DOWN_ARROW_KEY)
	{
		game->camera_offsets.y -= 100;
	}
	else if (key == A_KEY || key == LEFT_ARROW_KEY)
	{
		game->camera_offsets.x += 100;
	}
	else if (key == D_KEY || key == RIGHT_ARROW_KEY)
	{
		game->camera_offsets.x -= 100;
	}
	printf("x : %d | y : %d h : %d\n", game->camera_offsets.x,
		game->camera_offsets.y, game->map->height);
}

int	handle_key(int keycode, t_mlx *mlx)
{
	if (keycode == 65307 || keycode == -16778664)
	{
		mlx_loop_end(mlx->mlx);
	}
	on_key_pressed(keycode);
	ft_printf("pressed : %d\n", keycode);
	return (0);
}
