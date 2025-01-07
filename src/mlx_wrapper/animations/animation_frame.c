/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:36:20 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/07 14:05:11 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animations.h"

t_img	*extract_img_from(void *mlx, t_animation animation, int i)
{
	t_img	*new_img;
	int		new_pixel;
	int		img_pixel;
	int		x;
	int		y;
	int		x1;
	int		y1;

	y1 = 0;
	y = -1;
	new_img = mlx_new_image(mlx, animation.params.frame_length.x,
			animation.params.frame_length.y);
	if (!new_img)
		return (exit(1), NULL); // TODO
	while (++y < animation.params.frame_length.y)
	{
		x = -1;
		x1 = 0;
		while (++x < animation.params.frame_length.x)
		{
			*get_pixel(new_img, (t_vec2){x,
					y}) = *get_pixel(animation.img, (t_vec2){x
					+ animation.params.frame_length.x * i, y});
		}
	}
	return (new_img);
}

t_animation_frame	*create_animation_frames(void *mlx, t_animation_id id)
{
	t_animation_frame	*frame;
	t_animation_frame	*old;
	t_animation_frame	*first;
	t_animation			animation;
	int					i;

	i = 0;
	old = NULL;
	animation = get_animation(id);
	while (i < animation.params.frames_count)
	{
		frame = (t_animation_frame *)malloc(sizeof(t_animation_frame));
		if (!frame)
			return (exit(1), NULL); // TODO
		frame->current = extract_img_from(mlx, animation, i);
		frame->next = NULL;
		frame->animation = animation;
		if (old)
			old->next = frame;
		old = frame;
		if (i == 0)
			first = frame;
		i++;
	}
	old->next = first;
	return (first);
}

// void	free_rendering_queue(t_game *game)
// {
// 	t_animation_frame	*to_free;

// 	while (game->rendering_queue)
// 	{
// 		to_free = game->rendering_queue;
// 		game->rendering_queue = game->rendering_queue->next;
// 		free(to_free);
// 	}
// 	game->rendering_queue = NULL;
// }
