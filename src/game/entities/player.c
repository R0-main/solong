/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:10:54 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 14:51:33 by rguigneb         ###   ########.fr       */
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
	player->directions_textures[UP] = get_texture(PLAYER_TEXTURE_TOP);
	player->directions_textures[DOWN] = get_texture(PLAYER_TEXTURE_BOTTOM);
	player->directions_textures[RIGHT] = get_texture(PLAYER_TEXTURE_RIGHT);
	player->directions_textures[LEFT] = get_texture(PLAYER_TEXTURE_LEFT);
}

void	handle_player(t_game *game, t_entity *player)
{
	t_entity	*coin;
	t_entity	*exit;

	coin = get_entity_at_location(game, player->pos, COLLECTIBLE_TYPE);
	exit = get_entity_at_location(game, game->map->exit_coords, EXIT_TYPE);
	if (!exit)
		exit_error(ENTITIES_FIND_EXIT_ENTITY);
	if (coin)
	{
		remove_entity(coin);
		game->collected_collectible += 1;
		if (game->collected_collectible == game->map->collectible_count)
			exit->texture = get_texture(PLAYER_TEXTURE);
	}
	if (game->collected_collectible == game->map->collectible_count
		&& is_same_position(exit->pos, player->pos))
		exit_error("FINISH GAME");
	rotate_entity_texture(game, player, player->last_direction);
}
