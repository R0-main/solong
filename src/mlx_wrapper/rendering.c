/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:03:05 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/08 13:04:25 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

t_rendering_element	*create_rendering_element(t_img *img, t_img_data data,
		t_vec2 position)
{
	t_rendering_element	*r_element;

	r_element = (t_rendering_element *)malloc(sizeof(t_rendering_element));
	if (!r_element)
		return (NULL);
	r_element->img = img;
	r_element->img_data = data;
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

void	put_img_to_rendering_buffer(t_game *game, t_rendering_element *r_elem)
{
	int			y;
	int			x;
	int			pixel;
	int			buffer_pixel;
	int			d;

	y = -1;
	d = r_elem->img_data.line_bytes / 4;
	while (++y < r_elem->img->height)
	{
		x = -1;
		while (++x < r_elem->img->width)
		{
			pixel = (y * d) + (x);
			if (is_between((t_vec2){r_elem->position.x + x, r_elem->position.y
					+ y}, POSITION_ZERO, POSITION_MAX))
			{
				buffer_pixel = ((r_elem->position.y + y)
						* (game->rendering_buffer_data.line_bytes / 4))
					+ ((r_elem->position.x + x));
				if (((int32_t *)r_elem->img->data)[pixel] != 0x00000000)
					((int32_t *)game->rendering_buffer->data)[buffer_pixel] = ((int32_t *)r_elem->img->data)[pixel];
			}
		}
	}
}

void	proccess_rendering_buffer(t_game *game)
{
	t_rendering_element	*r_elem;
	int					i;

	if (!game->rendering_buffer)
		return ;
	i = 0;
	r_elem = game->rendering_queue;
	while (r_elem)
	{
		put_img_to_rendering_buffer(game, r_elem);
		r_elem = r_elem->next;
	}
	free_rendering_queue(game);
}
