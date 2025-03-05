/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_queue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:10:49 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/15 09:53:32 by rguigneb         ###   ########.fr       */
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

	if (!game || !game->init)
		return ;
	if (!game->rendering_queue)
		game->rendering_queue = r_elem;
	else
	{
		current = game->rendering_queue;
		r_elem->next = current;
		game->rendering_queue = r_elem;
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
