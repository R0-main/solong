/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:11:28 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 14:15:46 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	put_img_to_rendering_buffer(t_game *game, t_rendering_element *r_elem)
{
	int	y;
	int	x;
	int	buffer_pixel;
	int	d;
	int	c;

	y = -1;
	d = r_elem->img_data.line_bytes / 4;
	c = game->rendering_buffer_data.line_bytes / 4;
	while (++y < r_elem->img->height)
	{
		x = -1;
		while (++x < r_elem->img->width)
		{
			if (is_between((t_vec2){r_elem->position.x + x, r_elem->position.y
					+ y}, (t_vec2){0, 0}, (t_vec2){WIDTH - 1, HEIGHT}))
			{
				buffer_pixel = ((r_elem->position.y + y) * (c))
					+ ((r_elem->position.x + x));
				if (((int32_t *)r_elem->img->data)[(y * d) + (x)] != 0x00000000)
					((int32_t *)game->rendering_buffer->data)[buffer_pixel] = \
						((int32_t *)r_elem->img->data)[(y * d) + (x)];
			}
		}
	}
}

void	proccess_rendering_buffer(t_game *game)
{
	t_rendering_element	*r_elem;
	int					i;

	if (!game || !game->init)
		return ;
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
