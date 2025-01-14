/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:59:00 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 09:43:13 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H

# define RENDERING_H

# include "animations.h"
# include "game.h"
# include "textures.h"

t_rendering_element	*create_rendering_element(t_img *img, t_img_data data,
						t_vec2 position);

void				delete_from_rendering_proccess(t_rendering_element *r_elem);

void				add_to_rendering_proccess(t_rendering_element *r_elem,
						t_game *game);

void				proccess_rendering_buffer(t_game *game);

void				put_img_to_rendering_buffer(t_game *game,
						t_rendering_element *r_elem);

void				put_pixel_into_rendering_buffer(t_game *game,
						int32_t *buffer, int buffer_line_bits, t_vec2 coords,
						int32_t color);

void				free_rendering_queue(t_game *game);

void				draw_map(t_game *game);

void				render_asset(t_game *game, t_texture asset,
						t_vec2 position);

#endif
