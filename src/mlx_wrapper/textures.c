/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:14:38 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/28 13:04:04 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "textures.h"

int	get_pixel_index(t_img *asset, t_coordinates coords)
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;
	int	pixel;

	mlx_get_data_addr(asset, &pixel_bits, &line_bytes, &endian);
	pixel = (coords.y * line_bytes) + (coords.x * 4);
	return (pixel);
}


int32_t	*get_pixel(t_img *asset, t_coordinates coords)
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;
	int	pixel;

	mlx_get_data_addr(asset, &pixel_bits, &line_bytes, &endian);
	pixel = (coords.y * line_bytes) + (coords.x * 4);
	return ((int32_t *)(asset->data + pixel));
}

t_textures_atlas	*get_textures_atlas(void)
{
	static t_textures_atlas	atlas = {};

	return (&atlas);
}

void	add_asset(int id, t_img *img)
{
	t_textures_atlas	*textures_atlas;

	textures_atlas = get_textures_atlas();
	textures_atlas->atlas[id] = img;
}

int	load_texture(void *mlx, const char *path, int id)
{
	t_img	*img;
	int		h;
	int		w;

	img = mlx_xpm_file_to_image(mlx, (char *)path, &w, &h);
	if (!img)
	{
		// add message
		return (1);
	}
	// handle_transparency(img);
	add_asset(id, img);
	return (0);
}

void	load_black_screen_texture(void *mlx)
{
	t_img				*img;
	t_textures_atlas	*textures_atlas;

	// int					y;
	// int					x;
	// int					pixel;
	// int					pixel_bits;
	// int					line_bytes;
	// int					endian;
	// y = 0;
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

void	reset_rendering_buffer(t_game *game)
{
	int	i;

	i = 0;
	(void)game;
	// free(game->rendering_buffer->data);
	// game->rendering_buffer->data = malloc(1000000);
	while (i < (HEIGHT * WIDTH) * 4)
	{
		game->rendering_buffer->data[i] = 0;
		// game->rendering_buffer->data[i + 1] = 0;
		// game->rendering_buffer->data[i + 2] = 0;
		// game->rendering_buffer->data[i + 3] = 0;
		// game->rendering_buffer->data[i + 4] = 0;
		// game->rendering_buffer->data[i + 5] = 0;
		// game->rendering_buffer->data[i + 6] = 0;
		// game->rendering_buffer->data[i + 7] = 0;
		// game->rendering_buffer->data[i + 8] = 0;
		// game->rendering_buffer->data[i + 9] = 0;
		i++;
	}
}

static int	is_transparent_pixel(t_img *img, int pixel)
{
	return (img->data[pixel] != 120 && (img->data[pixel] == 0 && img->data[pixel
			+ 1] == 0 && img->data[pixel + 2] == 0 && img->data[pixel
			+ 3] == 0));
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
	int	x, y, dx, dy;

	// Récupérer les informations de mémoire des images
	mlx_get_data_addr(dest_img, &pixel_bits, &line_bytes, &endian);
	mlx_get_data_addr(img, &pixel_bits1, &line_bytes1, &endian1);
	if (ox < 0 || oy < 0)
		return ;

	// Parcourir chaque pixel de l'image source
	for (y = 0; y < img->height ; y++)
	{
		for (x = 0; x < img->width; x++)
		{
			// Obtenir l'indice du pixel source
			pixel = get_pixel_index(img, (t_coordinates){x, y});

			// Vérifier si le pixel est transparent
			if (is_transparent_pixel(img, pixel))
				continue;

			// Répliquer le pixel source dans un carré 2x2
			for (dy = 0; dy < 2; dy++)
			{
				for (dx = 0; dx < 2; dx++)
				{
					int dest_x = ox + x * 2 + dx;
					int dest_y = oy + y * 2 + dy;

					// S'assurer que les coordonnées sont dans les limites de l'image destination
					if (dest_x >= dest_img->width || dest_y >= dest_img->height)
						continue;

					// Obtenir l'indice du pixel destination
					buffer_pixel = get_pixel_index(dest_img, (t_coordinates){dest_x, dest_y});

					// Copier les données RGBA
					dest_img->data[buffer_pixel] = img->data[pixel];
					dest_img->data[buffer_pixel + 1] = img->data[pixel + 1];
					dest_img->data[buffer_pixel + 2] = img->data[pixel + 2];
					dest_img->data[buffer_pixel + 3] = img->data[pixel + 3];
				}
			}
		}
	}
}


// void	put_img_to_rendering_buffer(t_game *game, t_img *img, int ox, int oy)
// {
// 	int	pixel_bits;
// 	int	line_bytes;
// 	int	endian;
// 	int	pixel_bits1;
// 	int	line_bytes1;
// 	int	endian1;
// 	int	pixel;
// 	int	buffer_pixel;

// 	mlx_get_data_addr(game->rendering_buffer, &pixel_bits, &line_bytes,
// 		&endian);
// 	mlx_get_data_addr(img, &pixel_bits1, &line_bytes1, &endian1);
// 	for (int y = 0; y < img->height; ++y)
// 	{
// 		for (int x = 0; x < img->width; ++x)
// 		{
// 			if (y + oy < 0 || x + ox < 0)
// 				continue ;
// 			buffer_pixel = ((y + oy) * line_bytes) + ((x + ox) * 4);
// 			pixel = (y * line_bytes1) + (x * 4);
// 			if (y + oy > HEIGHT || x + ox > WIDTH)
// 				continue ;
// 			if (img->data[pixel] != 120 && (img->data[pixel] == 0
// 					&& img->data[pixel + 1] == 0 && img->data[pixel + 2] == 0
// 					&& img->data[pixel + 3] == 0))
// 				continue ;
// 			game->rendering_buffer->data[buffer_pixel] = img->data[pixel];
// 			game->rendering_buffer->data[buffer_pixel + 1] = img->data[pixel
// 				+ 1];
// 			game->rendering_buffer->data[buffer_pixel + 2] = img->data[pixel
// 				+ 2];
// 			game->rendering_buffer->data[buffer_pixel + 3] = img->data[pixel
// 				+ 3];
// 		}
// 	}
// }
