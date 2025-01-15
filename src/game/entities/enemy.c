/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:10:54 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/15 11:52:41 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "path_finding.h"

void	create_enemy_entity(t_vec2 pos)
{
	t_entity	*enemy;

	enemy = create_entity(ENEMY_TYPE, pos);
	enemy->hp = 20;
	enemy->texture = get_texture(ENEMY_TEXTURE);
}
