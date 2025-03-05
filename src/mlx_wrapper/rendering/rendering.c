/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:10:08 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/15 10:15:59 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	render_asset(t_game *game, t_texture asset, t_vec2 position)
{
	t_rendering_element	*r_elem;

	if (!asset.img)
		return ;
	r_elem = create_rendering_element(asset.img, asset.img_data, position);
	add_to_rendering_proccess(r_elem, game);
}

void	render_animation(t_game *game, t_animation_frame *asset,
		t_vec2 position)
{
	t_rendering_element	*r_elem;

	r_elem = create_rendering_element(asset->texture.img,
			asset->texture.img_data, position);
	add_to_rendering_proccess(r_elem, game);
}
