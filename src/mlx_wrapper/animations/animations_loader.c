/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_loader.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:20:01 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/07 16:36:45 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animations.h"

void	load_animations(void *mlx)
{
	t_animation_parameters	params;

	load_animation(mlx,
					"./assets/coin.xpm",
					COIN_ANIMATION,
					(t_animation_parameters){(t_vec2){/* x : */ 44,
														/* y : */ 25},
											/*speed :*/ 50,
											/*frame count :*/ 16});
}

void	unload_animations_first_frame(void *mlx)
{
	int					i;
	int					y;
	t_animations_atlas	*animations_atlas;
	t_animation_frame	*first_frame;
	t_animation_frame	*tmp;
	int					frames_count;

	i = 0;
	animations_atlas = get_animations_atlas();
	while (i < MAX_ANIMATIONS)
	{
		y = 0;
		first_frame = animations_atlas->first_frame[i++];
		if (!first_frame)
			continue ;
		frames_count = first_frame->animation.params.frames_count;
		while (first_frame && y++ < frames_count)
		{
			if (first_frame->current)
				mlx_destroy_image(mlx, first_frame->current);
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
