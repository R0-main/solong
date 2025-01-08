/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:22:39 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/08 12:04:52 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int32_t	*get_pixel(t_img *asset, t_vec2 coords)
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;
	int	pixel;

	mlx_get_data_addr(asset, &pixel_bits, &line_bytes, &endian);
	pixel = (coords.y * line_bytes) + (coords.x * 4);
	return ((int32_t *)(asset->data + pixel));
}

static void	put_2x2_pixel(t_img *dest_img, int32_t color, t_vec2 pos,
		t_vec2 offset)
{
	t_vec2	dc;
	t_vec2	dest;

	dc.y = -1;
	if (color == 0)
		return ;
	while (++dc.y < 2)
	{
		dc.x = -1;
		while (++dc.x < 2)
		{
			dest.x = offset.x + pos.x * 2 + dc.x;
			dest.y = offset.y + pos.y * 2 + dc.y;
			if (dest.x >= dest_img->width || dest.y >= dest_img->height)
				continue ;
			*get_pixel(dest_img, dest) = color;
		}
	}
}

void	put_img_to_into_img(t_img *dest_img, t_img *img, t_vec2 offset)
{
	t_vec2	pos;

	pos.y = -1;
	while (++pos.y < img->height)
	{
		pos.x = -1;
		while (++pos.x < img->width)
			put_2x2_pixel(dest_img, *get_pixel(img, pos), pos, offset);
	}
}

void	put_img_to_into_img_with_offset(t_img *dest_img, t_vec2 dest_offset,
		t_img *img, t_vec2 img_offset)
{
	t_vec2	pos;

	pos.y = -1;
	while (++pos.y < img->height)
	{
		pos.x = -1;
		while (++pos.x < img->width)
			put_2x2_pixel(dest_img, *get_pixel(img, (t_vec2){img_offset.x
					+ pos.x, img_offset.y + pos.y}), pos, dest_offset);
	}
}
