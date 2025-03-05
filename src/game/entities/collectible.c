/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:17:34 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/15 11:52:45 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "path_finding.h"

void	create_collectible_entity(t_vec2 pos)
{
	t_entity	*collectible;

	collectible = create_entity(COLLECTIBLE_TYPE, pos);
	collectible->idle_animation = get_animation_first_frame(COIN_ANIMATION);
	collectible->texture = collectible->idle_animation->texture;
}
