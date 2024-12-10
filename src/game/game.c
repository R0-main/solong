/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:30:56 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/10 15:18:26 by rguigneb         ###   ########.fr       */
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
	game->mlx = mlx;
	game->camera_offsets.x = -(game->map->witdh / 2);
	game->camera_offsets.y = (game->map->height / 4);
	draw_bg(game);
	test_game(game);
	return (0);
}
