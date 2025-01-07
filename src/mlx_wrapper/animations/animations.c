/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:27:22 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/07 11:34:31 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animations.h"

t_animations_atlas	*get_animations_atlas(void)
{
	static t_animations_atlas	atlas = {};

	return (&atlas);
}

bool	load_animation(void *mlx, const char *path, int id,
		t_animation_parameters params)
{
	t_img				*img;
	t_animation_frame	*first_frame;
	int					h;
	int					w;

	img = mlx_xpm_file_to_image(mlx, (char *)path, &w, &h);
	if (!img)
	{
		// add message // TODO;
		return (true);
	}
	add_animation_asset(id, img, params);
	first_frame = create_animation_frames(mlx, id);
	set_animation_first_frame(id, first_frame);
	return (false);
}

void	add_animation_asset(int id, t_img *img, t_animation_parameters params)
{
	t_animations_atlas	*atlas;

	if (id < MAX_ANIMATIONS)
	{
		atlas = get_animations_atlas();
		atlas->atlas[id] = (t_animation){img, params};
	}
}

void	set_animation_first_frame(t_animation_id id,
		t_animation_frame *first_frame)
{
	t_animations_atlas	*atlas;

	if (id < MAX_ANIMATIONS)
	{
		atlas = get_animations_atlas();
		atlas->first_frame[id] = first_frame;
	}
}

t_animation_frame	*get_animation_first_frame(t_animation_id id)
{
	t_animations_atlas	*atlas;

	if (id < MAX_ANIMATIONS)
	{
		atlas = get_animations_atlas();
		return (atlas->first_frame[id]);
	}
	return (NULL);
}

t_animation	get_animation(t_animation_id id)
{
	t_animations_atlas	*atlas;

	atlas = get_animations_atlas();
	if (id < MAX_ANIMATIONS)
	{
		return (atlas->atlas[id]);
	}
	return ((t_animation){0});
}
