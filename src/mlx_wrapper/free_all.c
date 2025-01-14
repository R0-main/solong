/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:52:26 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 13:17:49 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "rendering.h"

void	free_all(void)
{
	t_mlx	*mlx;
	t_game	*game;
	t_map	*map;

	mlx = get_mlx_vars();
	game = get_game_instance();
	map = get_map();
	if (map)
		free_map();
	free_entities(game);
	free_rendering_queue(game);
	if (mlx && mlx->mlx)
	{
		unload_assets(mlx->mlx);
		unload_animations(mlx->mlx);
		mlx_destroy_window(mlx->mlx, mlx->win);
		if (game && game->rendering_buffer)
			mlx_destroy_image(mlx->mlx, game->rendering_buffer);
		mlx_destroy_display(mlx->mlx);
	}
	free(mlx->mlx);
}
