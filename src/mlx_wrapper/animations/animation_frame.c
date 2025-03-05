/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:36:20 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/15 11:52:00 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animations.h"
#include "errors.h"

t_img	*extract_img_from(void *mlx, t_animation animation, int i)
{
	t_img	*new_img;

	new_img = mlx_new_image(mlx, animation.params.frame_length.x * 2,
			animation.params.frame_length.y * 2);
	if (!new_img)
		return (NULL);
	put_img_to_into_img_with_offset(new_img, (t_vec2){0, 0}, animation.img,
		(t_vec2){animation.params.frame_length.x * i, 0});
	return (new_img);
}

void	free_all_current_animations(void *mlx, t_animation_frame *first)
{
	t_animation_frame	*tmp;

	while (first)
	{
		tmp = first->next;
		mlx_destroy_image(mlx, first->texture.img);
		free(first);
		first = tmp;
	}
	exit_error("Fail to extract img from an animation");
}

void	init_animation_frame(t_animation animation, t_animation_frame *frame)
{
	t_img_data	data;

	mlx_get_data_addr(frame->texture.img, &data.pixel_bits, &data.line_bytes,
		&data.endian);
	frame->texture.img_data = data;
	frame->next = NULL;
	frame->animation = animation;
}

t_animation_frame	*create_animation_frames(void *mlx, t_animation_id id)
{
	t_load_animation	p;

	p.i = 0;
	p.old = NULL;
	p.first = NULL;
	p.animation = get_animation(id);
	while (p.i < p.animation.params.frames_count)
	{
		p.frame = (t_animation_frame *)malloc(sizeof(t_animation_frame));
		if (!p.frame)
			return (free_all_current_animations(mlx, p.first), NULL);
		p.frame->texture.img = extract_img_from(mlx, p.animation, p.i);
		if (!p.frame->texture.img)
			return (free(p.frame), free_all_current_animations(mlx, p.first),
				NULL);
		init_animation_frame(p.animation, p.frame);
		if (p.old)
			p.old->next = p.frame;
		p.old = p.frame;
		if (p.i == 0)
			p.first = p.frame;
		p.i++;
	}
	p.old->next = p.first;
	return (p.first);
}
