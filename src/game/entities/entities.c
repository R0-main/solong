/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:22:19 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/15 11:56:47 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "path_finding.h"
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
	entity->directions_textures[0] = (t_texture){0};
	entity->directions_textures[1] = (t_texture){0};
	entity->directions_textures[2] = (t_texture){0};
	entity->directions_textures[3] = (t_texture){0};
	entity->hp = 0;
	entity->path_to_follow = NULL;
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
	if (!game || !game->init)
		return ;
	tmp = game->entities;
	while (tmp->next != entity)
		tmp = tmp->next;
	tmp->next = entity->next;
	if (entity->path_to_follow)
		free_path_nodes(entity->path_to_follow);
	free(entity);
}

void	entities_loop(t_game *game)
{
	t_entity	*current;
	t_vec2		pos;

	if (!game || !game->init)
		return ;
	current = game->entities;
	while (current)
	{
		pos = get_to_world_coord(current->pos.x + 1, current->pos.y - 1);
		pos.x += get_min_x(game);
		if (current->idle_animation && game->tick % (100
				/ current->idle_animation->animation.params.speed) == 0)
		{
			current->texture = current->idle_animation->texture;
			current->idle_animation = current->idle_animation->next;
		}
		pos.x -= current->texture.img->width + game->camera_offsets.x;
		pos.y -= current->texture.img->height + game->camera_offsets.y;
		pos.x -= TILE_X / 1.85;
		pos.y += TILE_Y;
		if (current->type == PLAYER_TYPE)
			handle_player(game, current);
		render_asset(game, current->texture, pos);
		current = current->next;
	}
}
