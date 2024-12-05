/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:30:56 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/05 12:41:07 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	init_bg(t_mlx *mlx)
{
	t_img	*img;
	int		i;
	int		j;

	i = 0;
	j = 0;
	img = get_texture(GRASS_TEXTURE);
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, img, i, j);
			j += img->height;
		}
		i += img->width;
	}
	return (0);
}

int	game_init(t_mlx *mlx)
{
	init_bg(mlx);
	return (0);
}
