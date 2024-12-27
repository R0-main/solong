/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:03:05 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/27 16:57:57 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

t_rendering_element	*create_rendering_element(t_img *img,
		t_coordinates position)
{
	t_rendering_element	*r_element;

	r_element = (t_rendering_element *)malloc(sizeof(t_rendering_element));
	if (!r_element)
		return (NULL);
	r_element->img = img;
	r_element->position = position;
	r_element->next = NULL;
	r_element->prev = NULL;
	return (r_element);
}

void	add_to_rendering_proccess(t_rendering_element *r_elem, t_game *game)
{
	if (!game->rendering_queue)
		game->rendering_queue = r_elem;
	else
	{
		game->rendering_queue->next = r_elem;
		r_elem->prev = game->rendering_queue;
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
	if (r_elem->prev)
		r_elem->prev->next = r_elem->next;
	if (r_elem->next)
		r_elem->next->prev = r_elem->prev;
	free(r_elem);
}

t_rendering_element	*get_rendering_element_at_position(t_game *game,
		t_coordinates position)
{
	t_rendering_element	*begin;

	begin = game->rendering_queue;
	while (begin)
	{
		if (is_between(position, begin->position,
				(t_coordinates){begin->position.x + begin->img->width,
				begin->position.y + begin->img->height}))
			return (begin);
		begin = begin->next;
	}
	return (NULL);
}

void	set_img_pixel(t_img *image, int x, int y, int32_t color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < PIXEL_DEF)
	{
		j = -1;
		while (++j < PIXEL_DEF)
		{
			*get_pixel(image, (t_coordinates){x * PIXEL_DEF + i, y * PIXEL_DEF
					+ j}) = color;
		}
	}
	// if ((x * 4 + 3) < image->width && (y * 4 + 3) < image->height)
	// {
	// 	// Écrire les pixels du carré 4x4
	// 	for (int i = 0; i < 4; i++)
	// 		for (int j = 0; j < 4; j++)
	// }
}

void	proccess_rendering_buffer(t_game *game)
{
	int x;
	int y;
	t_rendering_element *r_element;
	int32_t *r_element_pixel;

	y = 0;
	if (!game->rendering_buffer)
		return ;
	while (y < game->rendering_buffer->height)
	{
		x = 0;
		while (x < game->rendering_buffer->width)
		{
			r_element = get_rendering_element_at_position(game,
					(t_coordinates){x, y});
			if (r_element)
				r_element_pixel = get_pixel(r_element->img, (t_coordinates){x
						- r_element->position.x, y - r_element->position.y});
			if (!r_element || *r_element_pixel == 0)
			{
				set_img_pixel(game->rendering_buffer, x / PIXEL_DEF, y
					/ PIXEL_DEF, 0x000FF000);
			}
			else
			{
				set_img_pixel(game->rendering_buffer, x / PIXEL_DEF, y
					/ PIXEL_DEF, *r_element_pixel);
			}
			x += PIXEL_DEF;
		}
		y += PIXEL_DEF;
	}
	free_rendering_queue(game);
}