/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_loader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:24:00 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/15 11:18:02 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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
	load_texture(mlx, "assets/player-bottom.xpm", PLAYER_TEXTURE_BOTTOM);
	load_texture(mlx, "assets/player-up.xpm", PLAYER_TEXTURE_TOP);
	load_texture(mlx, "assets/player-left.xpm", PLAYER_TEXTURE_LEFT);
	load_texture(mlx, "assets/player-right.xpm", PLAYER_TEXTURE_RIGHT);
	load_texture(mlx, "assets/tile.xpm", TILE_TEXTURE);
	load_texture(mlx, "assets/flag-closed.xpm", EXIT_CLOSE_TEXTURE);
	load_texture(mlx, "assets/flag-open.xpm", EXIT_OPEN_TEXTURE);
	load_texture(mlx, "assets/enemy.xpm", ENEMY_TEXTURE);
	load_texture(mlx, "assets/coin.xpm", COIN_TEXTURE);
	load_texture(mlx, "assets/font/0.xpm", FONT_ZERO_TEXTURE);
	load_texture(mlx, "assets/font/1.xpm", FONT_ONE_TEXTURE);
	load_texture(mlx, "assets/font/2.xpm", FONT_TWO_TEXTURE);
	load_texture(mlx, "assets/font/3.xpm", FONT_THREE_TEXTURE);
	load_texture(mlx, "assets/font/4.xpm", FONT_FOUR_TEXTURE);
	load_texture(mlx, "assets/font/5.xpm", FONT_FIVE_TEXTURE);
	load_texture(mlx, "assets/font/6.xpm", FONT_SIX_TEXTURE);
	load_texture(mlx, "assets/font/7.xpm", FONT_SEVEN_TEXTURE);
	load_texture(mlx, "assets/font/8.xpm", FONT_EIGHT_TEXTURE);
	load_texture(mlx, "assets/font/9.xpm", FONT_NINE_TEXTURE);
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
			mlx_destroy_image(mlx, texture.img);
	}
}
