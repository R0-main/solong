/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:14:38 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/08 12:18:17 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "textures.h"

t_textures_atlas	*get_textures_atlas(void)
{
	static t_textures_atlas	atlas = {};

	return (&atlas);
}

void	add_asset(int id, t_img *img)
{
	t_textures_atlas	*textures_atlas;
	t_img_data			data;

	if (id < MAX_TEXTURES)
	{
		textures_atlas = get_textures_atlas();
		textures_atlas->atlas[id].img = img;
		mlx_get_data_addr(img, &data.pixel_bits, &data.line_bytes, &data.endian);
		textures_atlas->atlas[id].img_data = data;
	}
}

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

t_texture	get_texture(int id)
{
	t_textures_atlas	*textures_atlas;

	textures_atlas = get_textures_atlas();
	return (textures_atlas->atlas[id]);
}
