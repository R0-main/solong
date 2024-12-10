/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:14:38 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/10 15:58:42 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
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

void	load_black_screen_texture(void *mlx)
{
	t_img				*img;
	int					y;
	// int					x;
	// int					pixel;
	// int					pixel_bits;
	// int					line_bytes;
	// int					endian;
	t_textures_atlas	*textures_atlas;

	y = 0;
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	// mlx_get_data_addr(img, &pixel_bits, &line_bytes, &endian);
	// while (y < HEIGHT)
	// {
	// 	x = 0;
	// 	while (x < WIDTH)
	// 	{
	// 		pixel = (y * line_bytes) + (x * 4);
	// 		img->data[pixel] = 1;
	// 		img->data[pixel + 1] = 0;
	// 		img->data[pixel + 2] = 125;
	// 		img->data[pixel + 3] = 125;
	// 		x += 1;
	// 	}
	// 	y += 1;
	// }
	textures_atlas = get_textures_atlas();
	textures_atlas->atlas[BLACK_SCREEN_TEXTURE] = img;
}

t_img	*get_texture(int id)
{
	t_textures_atlas	*textures_atlas;

	textures_atlas = get_textures_atlas();
	return (textures_atlas->atlas[id]);
}
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

t_img	*get_random_rotate_texture(int id, t_mlx *mlx)
{
	t_img	*img;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	char	*buffer2;
	int		pixel;
	int		color;
	t_img	*new_img;

	color = 0xABCDEF;
	img = get_texture(id);
	new_img = mlx_new_image(mlx->mlx, img->width, img->height);
	buffer2 = mlx_get_data_addr(new_img, &pixel_bits, &line_bytes, &endian);
	buffer = mlx_get_data_addr(img, &pixel_bits, &line_bytes, &endian);
	for (int y = 0; y < img->height; ++y)
	{
		for (int x = 0; x < img->width; ++x)
		{
			pixel = (y * line_bytes) + (x * 4);
			buffer2[pixel] = buffer[pixel] + 10;
			buffer2[pixel + 1] = buffer[pixel + 1];
			buffer2[pixel + 2] = buffer[pixel + 2];
			buffer2[pixel + 3] = 120;
			// mlx_pixel_put(mlx->mlx, mlx->win, x, y,
			// 	(int32_t)buffer[pixel]);
			// mlx_pixel_put(mlx->mlx, mlx->win, x, y,
			// 	(int32_t)buffer[pixel + 1]);
			// buffer[pixel] = buffer[pixel] + 125;
			// printf("%d", (int32_t)buffer[pixel]);
		}
		// printf("\n");
	}
	return (new_img);
}

int32_t	argb_to_int(int8_t alpha, int8_t red, int8_t green, int8_t blue)
{
	// Combine les valeurs ARGB en un entier 32 bits
	return (((int32_t)alpha << 24) | ((int32_t)red << 16) | ((int32_t)green << 8) | (int32_t)blue);
}

void	put_transparent_texture_on_window(int id, t_mlx *mlx, int ox, int oy)
{
	t_img	*img;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	int		pixel;

	img = get_texture(id);
	buffer = mlx_get_data_addr(img, &pixel_bits, &line_bytes, &endian);
	for (int y = 0; y < img->height; ++y)
	{
		for (int x = 0; x < img->width; ++x)
		{
			pixel = (y * line_bytes) + (x * 4);
			if (buffer[pixel] == 0 && buffer[pixel + 1] == 0 && buffer[pixel
				+ 2] == 0 && buffer[pixel + 3] == 0)
				continue ;
			mlx_pixel_put(mlx->mlx, mlx->win, x + ox, y + oy, *(int *)(buffer
					+ pixel));
		}
	}
}

void	reset_rendering_buffer(t_game *game)
{
	int	i;

	i = 0;
	(void)game;
	// free(game->rendering_buffer->data);
	// game->rendering_buffer->data = malloc(1000000);
	while (i < HEIGHT * WIDTH * 4)
	{
		game->rendering_buffer->data[i] = 0;
		i++;
	}
}

void	put_img_to_into_img(t_img *dest_img, t_img *img, int ox, int oy)
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;
	int	pixel_bits1;
	int	line_bytes1;
	int	endian1;
	int	pixel;
	int	buffer_pixel;

	// int		pixel_1;
	mlx_get_data_addr(dest_img, &pixel_bits, &line_bytes,
		&endian);
	mlx_get_data_addr(img, &pixel_bits1, &line_bytes1, &endian1);
	// if (dest_img->width < img->width || dest_img->height < img->height)
	// 	return;
	for (int y = 0; y < img->height; ++y)
	{
		for (int x = 0; x < img->width; ++x)
		{
			if (y + oy < 0 || x + ox < 0 )
				continue ;
			buffer_pixel = ((y + oy) * line_bytes) + ((x + ox) * 4);
			pixel = (y * line_bytes1) + (x * 4);
			if (dest_img->width < x + ox || dest_img->height < y + oy )
				continue;
			if (img->data[pixel] != 120 && (img->data[pixel] == 0
					&& img->data[pixel + 1] == 0 && img->data[pixel + 2] == 0
					&& img->data[pixel + 3] == 0))
				continue ;
			dest_img->data[buffer_pixel] = img->data[pixel];
			dest_img->data[buffer_pixel + 1] = img->data[pixel
				+ 1];
			dest_img->data[buffer_pixel + 2] = img->data[pixel
				+ 2];
			dest_img->data[buffer_pixel + 3] = img->data[pixel
				+ 3];
		}
	}
}


void	put_img_to_rendering_buffer(t_game *game, t_img *img, int ox, int oy)
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;
	int	pixel_bits1;
	int	line_bytes1;
	int	endian1;
	int	pixel;
	int	buffer_pixel;

	// int		pixel_1;
	mlx_get_data_addr(game->rendering_buffer, &pixel_bits, &line_bytes,
		&endian);
	mlx_get_data_addr(img, &pixel_bits1, &line_bytes1, &endian1);
	for (int y = 0; y < img->height; ++y)
	{
		for (int x = 0; x < img->width; ++x)
		{
			if (y + oy < 0 || x + ox < 0 )
				continue ;
			buffer_pixel = ((y + oy) * line_bytes) + ((x + ox) * 4);
			pixel = (y * line_bytes1) + (x * 4);
			if (y + oy > HEIGHT || x + ox > WIDTH)
				continue ;
			if (img->data[pixel] != 120 && (img->data[pixel] == 0
					&& img->data[pixel + 1] == 0 && img->data[pixel + 2] == 0
					&& img->data[pixel + 3] == 0))
				continue ;
			game->rendering_buffer->data[buffer_pixel] = img->data[pixel];
			game->rendering_buffer->data[buffer_pixel + 1] = img->data[pixel
				+ 1];
			game->rendering_buffer->data[buffer_pixel + 2] = img->data[pixel
				+ 2];
			game->rendering_buffer->data[buffer_pixel + 3] = img->data[pixel
				+ 3];
		}
	}
}
