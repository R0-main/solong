/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_loader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:24:00 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 11:25:55 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "errors.h"

int	load_texture(void *mlx, const char *path, int id)
{
	t_img	*img;
	int		h;
	int		w;

	img = mlx_xpm_file_to_image(mlx, (char *)path, &w, &h);
	if (!img)
		return (exit_error("failed to load texture !"), 1);
	add_asset(id, img);
	return (0);
}

void	load_assets(void *mlx)
{
	load_texture(mlx, "assets/player.xpm", PLAYER_TEXTURE);
	load_texture(mlx, "assets/player-bottom.xpm", PLAYER_TEXTURE_BOTTOM);
	load_texture(mlx, "assets/player-up.xpm", PLAYER_TEXTURE_TOP);
	load_texture(mlx, "assets/player-left.xpm", PLAYER_TEXTURE_LEFT);
	load_texture(mlx, "assets/player-right.xpm", PLAYER_TEXTURE_RIGHT);
	load_texture(mlx, "assets/tile_022.xpm", TILE_TEXTURE);
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
