/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:52:26 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/08 09:36:06 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	free_all(void)
{
	t_mlx	*mlx;
	t_game	*game;

	mlx = get_mlx_vars();
	game = get_game_instance();
	if (!mlx)
		return ;
	if (mlx->mlx)
	{
		unload_assets(mlx->mlx);
		unload_animations(mlx->mlx);
		mlx_destroy_window(mlx->mlx, mlx->win);
		if (game && game->rendering_buffer)
			mlx_destroy_image(mlx->mlx, game->rendering_buffer);
	}
	free_map();
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
}