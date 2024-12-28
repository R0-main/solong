/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:35:40 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/28 12:49:23 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx_wrapper.h"

void	on_key_pressed(int key)
{
	t_game	*game;
	// t_coordinates	coords;

	game = get_game_instance();
	// coords = get_to_world_coord(game->camera_offsets.x, game->camera_offsets.y);
	// printf("x: %d\n", game->camera_offsets.x);
	// printf("y: %d\n", game->camera_offsets.y);
	// if (coords.x + 1 <= game->map->witdh || coords.y + 1 <= game->map->height)
	// 	return ;
	// if (coords.x - 1 >= game->map->witdh || coords.y - 1 >= game->map->height)
	// 	return ;
	if (key == W_KEY || key == UP_ARROW_KEY)
	{
		// forward
		game->camera_offsets.y += 1;
		// game->camera_offsets.x += 1;
	}
	else if (key == S_KEY || key == DOWN_ARROW_KEY)
	{
		// backward
		game->camera_offsets.y -= 1;
		// game->camera_offsets.x -= 1;
	}
	else if (key == A_KEY || key == LEFT_ARROW_KEY)
	{
		// left
		game->camera_offsets.x += 1;
		// game->camera_offsets.y -= 1;
	}
	else if (key == D_KEY || key == RIGHT_ARROW_KEY)
	{
		// right
		game->camera_offsets.x -= 1;
		// game->camera_offsets.y += 1;
	}
	printf("x : %d | y : %d h : %d\n", game->camera_offsets.x, game->camera_offsets.y, game->map->height);
}
