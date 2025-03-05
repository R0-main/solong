/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:10:54 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/15 10:55:10 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "path_finding.h"

void	create_player_entity(t_game *game)
{
	t_entity	*player;

	player = create_entity(PLAYER_TYPE, game->map->player_spawnpoint);
	player->hp = 20;
	player->texture = get_texture(PLAYER_TEXTURE_BOTTOM);
	player->directions_textures[UP] = get_texture(PLAYER_TEXTURE_TOP);
	player->directions_textures[DOWN] = get_texture(PLAYER_TEXTURE_BOTTOM);
	player->directions_textures[RIGHT] = get_texture(PLAYER_TEXTURE_RIGHT);
	player->directions_textures[LEFT] = get_texture(PLAYER_TEXTURE_LEFT);
}

void	handle_player(t_game *game, t_entity *player)
{
	t_entity	*entity;
	t_entity	*exit;

	entity = get_entity_at_location_diffrent_from(game, player->pos, player);
	exit = get_entity_at_location(game, game->map->exit_coords, EXIT_TYPE);
	if (!exit)
		exit_error(ENTITIES_FIND_EXIT_ENTITY);
	if (entity && entity->type == COLLECTIBLE_TYPE)
	{
		remove_entity(entity);
		game->collected_collectible += 1;
		if (game->collected_collectible == game->map->collectible_count)
			exit->texture = get_texture(EXIT_OPEN_TEXTURE);
	}
	else if (entity && entity->type == ENEMY_TYPE)
	{
		exit_log(GAME_OVER_LOG);
	}
	else if (entity && entity->type == EXIT_TYPE
		&& game->collected_collectible == game->map->collectible_count
		&& is_same_position(entity->pos, player->pos))
		exit_log(GAME_WON_LOG);
	rotate_entity_texture(game, player, player->last_direction);
}
