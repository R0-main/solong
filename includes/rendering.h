/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:59:00 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/27 16:09:06 by rguigneb         ###   ########.fr       */
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

#endif