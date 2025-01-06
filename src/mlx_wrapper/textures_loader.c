/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_loader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:24:00 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/06 12:22:20 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

void	load_assets(void *mlx)
{
	load_texture(mlx, "assets/grass.xpm", GRASS_TEXTURE);
	load_texture(mlx, "assets/player.xpm", PLAYER_TEXTURE);
	load_texture(mlx, "assets/grass122.xpm", SARAH_TEXTURE);
	load_texture(mlx, "assets/tile_022.xpm", TILE_TEXTURE);
	load_texture(mlx, "assets/test_tile.xpm", TEST_TILE_TEXTURE);
	load_texture(mlx, "assets/rock.xpm", ROCK);
	load_black_screen_texture(mlx);
}

void	unload_assets(void *mlx)
{
	int					i;
	t_textures_atlas	*textures_atlas;
	t_img				*img;

	i = 0;
	textures_atlas = get_textures_atlas();
	while (i < MAX_TEXTURES)
	{
		img = textures_atlas->atlas[i++];
		if (img)
		{
			mlx_destroy_image(mlx, img);
			printf("[ASSETS] Loaded !\n");
		}
	}
}
