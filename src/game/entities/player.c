/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:10:54 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 10:08:53 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "path_finding.h"

void	create_player_entity(t_game *game)
{
	t_entity	*player;

	player = create_entity(PLAYER_TYPE, game->map->player_spawnpoint);
	player->hp = 20;
	player->texture = get_texture(PLAYER_TEXTURE);
	player->walking_animations[UP] = get_animation_first_frame(COIN_ANIMATION);
	player->walking_animations[DOWN] = get_animation_first_frame(COIN_ANIMATION);
	player->walking_animations[RIGHT] = get_animation_first_frame(COIN_ANIMATION);
	player->walking_animations[LEFT] = get_animation_first_frame(COIN_ANIMATION);
}
