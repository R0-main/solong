/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:59:00 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 14:16:38 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H

# define RENDERING_H

# include "animations.h"
# include "game.h"
# include "mlx_int.h"
# include "mlx_wrapper.h"
# include "textures.h"
# include "utils.h"

typedef struct s_game			t_game;

typedef struct s_rendering_element
{
	t_vec2						position;
	t_img						*img;
	t_img_data					img_data;
	struct s_rendering_element	*next;
}								t_rendering_element;

// -----------------------------------------
//
//    Rendering Buffer Section
//
// -----------------------------------------

t_rendering_element				*create_rendering_element(t_img *img,
									t_img_data data, t_vec2 position);
void							free_rendering_queue(t_game *game);
void							add_to_rendering_proccess(
									t_rendering_element *r_elem,
									t_game *game);
void							proccess_rendering_buffer(t_game *game);
void							put_img_to_rendering_buffer(t_game *game,
									t_rendering_element *r_elem);

// -----------------------------------------
//
//    Map Rendering Section
//
// -----------------------------------------

void							draw_map(t_game *game);

// -----------------------------------------
//
//    Texture / Animations Rendering Section
//
// -----------------------------------------

void							render_asset(t_game *game, t_texture asset,
									t_vec2 position);
void							render_animation(t_game *game,
									t_animation_frame *asset, t_vec2 position);

#endif
