/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:59:00 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/07 08:38:53 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H

# define RENDERING_H

# include "game.h"

t_rendering_element	*create_rendering_element(t_img *img,
						t_coordinates position);

void				delete_from_rendering_proccess(t_rendering_element *r_elem);

void				add_to_rendering_proccess(t_rendering_element *r_elem,
						t_game *game);

void				proccess_rendering_buffer(t_game *game);

void				put_img_to_rendering_buffer(t_game *game,
						t_rendering_element *r_elem);

void				put_pixel_into_rendering_buffer(t_game *game, int32_t *buffer,
						int buffer_line_bits, t_coordinates coords,
						int32_t color);

#endif
