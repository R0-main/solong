/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_loader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:24:00 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/08 12:18:48 by rguigneb         ###   ########.fr       */
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
	load_texture(mlx, "assets/rock.xpm", ROCK_TEXTURE);
	load_texture(mlx, "assets/coin.xpm", COIN_TEXTURE);
}

void	unload_assets(void *mlx)
{
	int					i;
	t_textures_atlas	*textures_atlas;
	t_texture			texture;

	i = 0;
	textures_atlas = get_textures_atlas();
	while (i < MAX_TEXTURES)
	{
		texture = textures_atlas->atlas[i++];
		if (texture.img)
		{
			mlx_destroy_image(mlx, texture.img);
			printf("[ASSETS] UnLoaded !\n");
		}
	}
}
