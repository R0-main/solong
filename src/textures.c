/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:14:38 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/05 12:36:03 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

t_textures_atlas	*get_textures_atlas(void)
{
	static t_textures_atlas	atlas = {};

	return (&atlas);
}

int	load_texture(void *mlx, const char *path, int id)
{
	t_textures_atlas	*textures_atlas;
	t_img				*img;
	int					h;
	int					w;

	img = mlx_xpm_file_to_image(mlx, (char *)path, &w, &h);
	if (!img)
	{
		// add message
		return (1);
	}
	textures_atlas = get_textures_atlas();
	textures_atlas->atlas[id] = img;
	return (0);
}

t_img	*get_texture(int id)
{
	t_textures_atlas	*textures_atlas;

	textures_atlas = get_textures_atlas();
	return (textures_atlas->atlas[id]);
}

t_img	*get_random_rotate_texture(int id)
{
	t_img	*img;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	int		pixel;
	int		color;

	color = 0xABCDEF;
	img = get_texture(id);
	buffer = mlx_get_data_addr(img, &pixel_bits, &line_bytes, &endian);
	for (int y = 0; y < img->height; ++y)
		for (int x = 0; x < img->width; ++x)
		{
			pixel = (y * line_bytes) + (x * 4);
			if (pixel % 12 == 0)
			{
				buffer[pixel + 0] = buffer[pixel + 1 + 4];
				buffer[pixel + 1] = buffer[pixel + 2 + 4];
				buffer[pixel + 2] = buffer[pixel + 3 + 4];
				// buffer[pixel + 3] = 5;
			}
		}
	return (img);
}
