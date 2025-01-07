/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:03:05 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/07 09:42:45 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

t_rendering_element	*create_rendering_element(t_img *img, t_vec2 position)
{
	t_rendering_element	*r_element;

	r_element = (t_rendering_element *)malloc(sizeof(t_rendering_element));
	if (!r_element)
		return (NULL);
	r_element->img = img;
	r_element->position = position;
	r_element->next = NULL;
	return (r_element);
}

void	add_to_rendering_proccess(t_rendering_element *r_elem, t_game *game)
{
	t_rendering_element	*current;

	if (!game->rendering_queue)
		game->rendering_queue = r_elem;
	else
	{
		current = game->rendering_queue;
		while (current)
		{
			if (current->next == NULL)
			{
				current->next = r_elem;
				break ;
			}
			current = current->next;
		}
		// r_elem->next = game->rendering_queue;
		// game->rendering_queue = r_elem;
	}
}

void	free_rendering_queue(t_game *game)
{
	t_rendering_element	*to_free;

	while (game->rendering_queue)
	{
		to_free = game->rendering_queue;
		game->rendering_queue = game->rendering_queue->next;
		free(to_free);
	}
	game->rendering_queue = NULL;
}

void	delete_from_rendering_proccess(t_rendering_element *r_elem)
{
	free(r_elem);
}

t_rendering_element	*get_rendering_element_at_position(t_game *game,
		t_vec2 position)
{
	t_rendering_element	*begin;

	begin = game->rendering_queue;
	while (begin)
	{
		if (is_between(position, begin->position, (t_vec2){begin->position.x
				+ begin->img->width, begin->position.y + begin->img->height}))
			return (begin);
		begin = begin->next;
	}
	return (NULL);
}

void	set_img_pixel(t_img *image, int x, int y, int32_t color)
{
	// int	i;
	// int	j;
	// i = -1;
	// while (++i < PIXEL_DEF)
	// {
	// 	j = -1;
	// 	while (++j < PIXEL_DEF)
	// 	{
	// 		*get_pixel(image, (t_coordinates){x * PIXEL_DEF + i, y * PIXEL_DEF
	// 				+ j}) = color;
	// 	}
	// }
	*get_pixel(image, (t_vec2){x, y}) = color;
	// if ((x * 4 + 3) < image->width && (y * 4 + 3) < image->height)
	// {
	// 	// Écrire les pixels du carré 4x4
	// 	for (int i = 0; i < 4; i++)
	// 		for (int j = 0; j < 4; j++)
	// }
}

void	fill_line(int32_t *buffer, int line_bytes, int y, int width,
		int32_t color)
{
	int32_t	*line;

	line = (int32_t *)((char *)buffer + (y * line_bytes));
	for (int x = 0; x < width; x++)
	{
		line[x] = color;
	}
}

void	put_img_to_rendering_buffer(t_game *game, t_rendering_element *r_elem)
{
	t_img_data	img_data;
	int			y;
	int			x;
	int			pixel;
	int			buffer_pixel;

	y = 0;
	mlx_get_data_addr(r_elem->img, &img_data.pixel_bits, &img_data.line_bytes,
		&img_data.endian);
	while (y < r_elem->img->height)
	{
		x = 0;
		while (x < r_elem->img->width)
		{
			pixel = (y * img_data.line_bytes / 4) + (x);
			if (is_between((t_vec2){r_elem->position.x + x, r_elem->position.y
					+ y}, POSITION_ZERO, POSITION_MAX))
			{
				buffer_pixel = ((r_elem->position.y + y)
						* (game->rendering_buffer_data.line_bytes / 4))
					+ ((r_elem->position.x + x));
				if (((int32_t *)r_elem->img->data)[pixel] != 0x00000000)
					((int32_t *)game->rendering_buffer->data)[buffer_pixel] = ((int32_t *)r_elem->img->data)[pixel];
			}
			x++;
		}
		y++;
	}
}

void	put_img_to_rendering_buffer_once(t_game *game,
		t_rendering_element *r_elem)
{
	t_img_data	img_data;
	int			i;
	int			pixel;
	int			buffer_pixel;
	int			y;
	int32_t		*img_buffer;

	img_buffer = r_elem->img->data;
	i = 0;
	mlx_get_data_addr(r_elem->img, &img_data.pixel_bits, &img_data.line_bytes,
		&img_data.endian);
	while (i < (r_elem->img->height * r_elem->img->width) / 6)
	{
		if (i % r_elem->img->width == 0)
			y++;
		*((t_pixels_optimisation *)game->rendering_buffer->data + i + (y
					* img_data.line_bytes)) = (t_pixels_optimisation){
			img_buffer[i],
			img_buffer[i + 1],
			img_buffer[i + 2],
			img_buffer[i + 3],
			img_buffer[i + 4],
			img_buffer[i + 5],
		};
		i++;
	}
}

void	put_pixel_into_rendering_buffer(t_game *game, int32_t *rendering_data,
		int buffer_line_bits, t_vec2 coords, int32_t color)
{
	int	buffer_pixel;

	buffer_pixel = ((1 + coords.y) * buffer_line_bits) + (0 + coords.x);
	rendering_data[buffer_pixel] = color;
	buffer_pixel = ((1 + coords.y) * buffer_line_bits) + (1 + coords.x);
	rendering_data[buffer_pixel] = color;
	buffer_pixel = ((0 + coords.y) * buffer_line_bits) + (1 + coords.x);
	rendering_data[buffer_pixel] = color;
	buffer_pixel = ((0 + coords.y) * buffer_line_bits) + (0 + coords.x);
	rendering_data[buffer_pixel] = color;
	// y = -1;
	// while (++y < 2)
	// {
	// 	x = -1;
	// 	while (++x < 2)
	// 	{
	// 	}
	// }
}

#define IDK_HOW_TO_NAME_THAT (HEIGHT * WIDTH) / 6

void	proccess_rendering_buffer(t_game *game)
{
	t_rendering_element		*r_elem;
	int						i;
	int						y;
	int						color;
	double					time_taken;
	t_pixels_optimisation	*buffer;

	if (!game->rendering_buffer)
		return ;
	i = 0;
	color = 0x00FF0000;
	// clock_t start, end;
	// start = clock();
	// buffer = (t_pixels_optimisation *)game->rendering_buffer->data;
	// while (i < IDK_HOW_TO_NAME_THAT)
	// {
	// 	buffer[i] = (t_pixels_optimisation){
	// 		color,
	// 		color,
	// 		color,
	// 		color,
	// 		color,
	// 		color,
	// 	};
	// 	i += 1;
	// }
	// end = clock();
	// time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
	// printf("Temps d'exécution : %.3f ms\n", time_taken);
	r_elem = game->rendering_queue;
	while (r_elem)
	{
		put_img_to_rendering_buffer(game, r_elem);
		r_elem = r_elem->next;
	}
	// // int32_t color = 0x00FF0000; // Rouge
	// // int pixel;
	// // mlx_get_data_addr(game->rendering_buffer, &pixel_bits, &line_bytes,
	// 	&endian);
	// 	// printf("line bytes : %d\n", line_bytes);
	// 	// for (int y = 0; y < HEIGHT; y++) {
	// 	//
	// 		// int32_t *line = (int32_t *)((char *)game->rendering_buffer->data
	// 		+ (y * line_bytes));
	// 		//     for (int x = 0; x < WIDTH ; x++) {
	// 		// 		// pixel = (y * line_bytes) + (x * 4);
	// 		//         game->rendering_buffer->data[pixel] = color;
	// 		//     }
	// 		// }
	free_rendering_queue(game);
}
