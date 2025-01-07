/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:30:56 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/07 16:07:43 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_game	*get_game_instance(void)
{
	static t_game	game_instance = {};

	return (&game_instance);
}

int	game_init(t_mlx *mlx)
{
	t_game	*game;

	game = get_game_instance();
	game->map = get_map();
	print_map();
	game->rendering_buffer = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!game->rendering_buffer)
		return (1);
	game->rendering_buffer_data.endian = 0;
	game->rendering_buffer_data.line_bytes = 0;
	game->rendering_buffer_data.pixel_bits = 0;
	mlx_get_data_addr(game->rendering_buffer,
		&game->rendering_buffer_data.pixel_bits,
		&game->rendering_buffer_data.line_bytes,
		&game->rendering_buffer_data.endian);
	game->mlx = mlx;
	game->camera_offsets.x = 0; // -(game->map->witdh / 2);
	game->camera_offsets.y = 0; // game->map->height / 4);
	// draw_bg(game);
	// printf("game : %d\n", game->map->witdh);
	// printf("coords : %d %d\n", game->camera_offsets.x, game->camera_offsets.y);
	// game->map->map_img = mlx_new_image(mlx->mlx. 110, 100);
	// return (1);
	init_map_img(game);
	mlx_get_data_addr(game->map->map_img, &game->map->map_img_data.pixel_bits,
		&game->map->map_img_data.line_bytes, &game->map->map_img_data.endian);
	return (0);
}
