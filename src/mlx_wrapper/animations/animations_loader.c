/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_loader.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:20:01 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 12:53:46 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animations.h"
#include "errors.h"

bool	load_animation(void *mlx, const char *path, int id,
		t_animation_parameters params)
{
	t_img				*img;
	t_animation_frame	*first_frame;
	int					h;
	int					w;

	img = mlx_xpm_file_to_image(mlx, (char *)path, &w, &h);
	if (!img)
		exit_error("Fail to load animation image !");
	add_animation_asset(id, img, params);
	first_frame = create_animation_frames(mlx, id);
	set_animation_first_frame(id, first_frame);
	return (false);
}

void	load_animations(void *mlx)
{
	t_animation_parameters	params;

	load_animation(mlx, "./assets/coin.xpm", COIN_ANIMATION,
		(t_animation_parameters){(t_vec2){44, 25}, 10, 16});
}

void	unload_animations_first_frame(void *mlx)
{
	int					i;
	int					y;
	t_animation_frame	*first_frame;
	t_animation_frame	*tmp;
	int					frames_count;

	i = 0;
	while (i < MAX_ANIMATIONS)
	{
		y = 0;
		if (!get_animations_atlas())
			return ;
		first_frame = get_animations_atlas()->first_frame[i++];
		if (!first_frame)
			continue ;
		frames_count = first_frame->animation.params.frames_count;
		while (first_frame && y++ < frames_count)
		{
			if (first_frame->texture.img)
				mlx_destroy_image(mlx, first_frame->texture.img);
			tmp = first_frame->next;
			free(first_frame);
			first_frame = tmp;
		}
	}
}

void	unload_animations(void *mlx)
{
	int					i;
	t_animations_atlas	*animations_atlas;
	t_animation			animation;
	t_animation_frame	*first_frame;

	i = 0;
	animations_atlas = get_animations_atlas();
	while (i < MAX_ANIMATIONS)
	{
		animation = animations_atlas->atlas[i++];
		if (animation.img)
			mlx_destroy_image(mlx, animation.img);
	}
	unload_animations_first_frame(mlx);
}
