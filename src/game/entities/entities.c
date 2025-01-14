/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:22:19 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 13:12:55 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "rendering.h"

t_entity	*create_entity(t_entity_type type, t_vec2 pos)
{
	t_entity	*entity;

	entity = (t_entity *)malloc(sizeof(t_entity));
	if (!entity)
		exit_error(ENTITIES_MALLOC_FAILED);
	entity->type = type;
	entity->pos = pos;
	entity->next = NULL;
	entity->idle_animation = NULL;
	entity->walking_animations[0] = NULL;
	entity->walking_animations[1] = NULL;
	entity->walking_animations[2] = NULL;
	entity->walking_animations[3] = NULL;
	entity->hp = 0;
	entity->direction = DOWN;
	entity->last_direction = DOWN;
	entity->texture = (t_texture){0};
	add_to_entities_list(entity);
	return (entity);
}

void	remove_entity(t_entity *entity)
{
	t_entity	*tmp;
	t_game		*game;

	game = get_game_instance();
	if (!game)
		return ;
	tmp = game->entities;
	while (tmp->next != entity)
		tmp = tmp->next;
	tmp->next = entity->next;
	free(entity);
}

void	add_to_entities_list(t_entity *entity)
{
	t_entity	*tmp;
	t_game		*game;

	game = get_game_instance();
	if (!game)
		return ;
	if (!game->entities)
		game->entities = entity;
	else
	{
		tmp = game->entities;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = entity;
		entity->next = NULL;
	}
}

t_entity	*get_entity_at_location(t_game *game, t_vec2 pos,
		t_entity_type type)
{
	t_entity	*current;

	current = game->entities;
	while (current)
	{
		if (is_same_position(current->pos, pos) && current->type == type)
			return (current);
		current = current->next;
	}
	return (NULL);
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
}

void	entities_loop(t_game *game)
{
	t_entity	*current;
	t_vec2		pos;

	if (!game)
		return ;
	current = game->entities;
	while (current)
	{
		pos = get_to_world_coord(game, current->pos.x, current->pos.y - 1);
		pos.x += get_min_x(game);
		pos.x -= game->camera_offsets.x;
		pos.y -= game->camera_offsets.y;
		pos.x -= TILE_X;
		pos.y += TILE_Y / 2;
		if (current->idle_animation && game->tick % (100
				/ current->idle_animation->animation.params.speed) == 0)
		{
			current->texture = current->idle_animation->texture;
			current->idle_animation = current->idle_animation->next;
		}
		render_asset(game, current->texture, pos);
		if (current->type == PLAYER_TYPE)
			handle_player(game, current);
		current = current->next;
	}
}
