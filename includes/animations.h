/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:25:13 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/08 12:32:06 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATIONS_H

# define ANIMATIONS_H

# include "textures.h"
# include "game.h"
# include "mlx.h"
# include "mlx_int.h"

typedef enum e_animations
{
	COIN_ANIMATION,
}								t_animation_id;

# define MAX_ANIMATIONS 256

typedef struct s_animation_parameters
{
	t_vec2						frame_length;
	int							speed;
	int							frames_count;
}								t_animation_parameters;

typedef struct s_animation
{
	t_img						*img;
	t_animation_parameters		params;
}								t_animation;

typedef struct s_animation_frame
{
	t_texture					texture;
	t_animation					animation;
	struct s_animation_frame	*next;
}								t_animation_frame;

typedef struct s_animations_atlas
{
	t_animation					atlas[MAX_ANIMATIONS];
	t_animation_frame			*first_frame[MAX_ANIMATIONS];
}								t_animations_atlas;

typedef struct s_load_animation
{
	t_animation_frame			*frame;
	t_animation_frame			*old;
	t_animation_frame			*first;
	t_animation					animation;
	int							i;
}								t_load_animation;

t_animations_atlas				*get_animations_atlas(void);
void							add_animation_asset(int id, t_img *img,
									t_animation_parameters params);
bool							load_animation(void *mlx, const char *path,
									int id, t_animation_parameters params);

t_animation						get_animation(t_animation_id id);
t_img							*get_animation_asset(t_animation_id id);

t_animation_frame				*create_animation_frames(void *mlx,
									t_animation_id id);

void							set_animation_first_frame(t_animation_id id,
									t_animation_frame *first_frame);
t_animation_frame				*get_animation_first_frame(t_animation_id id);

void							load_animations(void *mlx);
void							unload_animations(void *mlx);

#endif