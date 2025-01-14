/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:17:34 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 10:09:02 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "path_finding.h"

void	create_collectible_entity(t_game *game, t_vec2 pos)
{
	t_entity	*collectible;

	collectible = create_entity(COLLECTIBLE_TYPE, pos);
	collectible->texture = get_texture(COIN_TEXTURE);
	collectible->idle_animation = get_animation_first_frame(COIN_ANIMATION);
}
