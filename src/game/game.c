/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:30:56 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/06 17:58:16 by rguigneb         ###   ########.fr       */
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
	draw_bg(game);
	return (0);
}
