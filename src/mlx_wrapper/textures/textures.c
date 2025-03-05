/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:14:38 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/15 09:01:31 by rguigneb         ###   ########.fr       */
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
		mlx_get_data_addr(img, &data.pixel_bits, &data.line_bytes,
			&data.endian);
		textures_atlas->atlas[id].img_data = data;
	}
}

t_texture	get_texture(int id)
{
	t_textures_atlas	*textures_atlas;

	textures_atlas = get_textures_atlas();
	return (textures_atlas->atlas[id]);
}
