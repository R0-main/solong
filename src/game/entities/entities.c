/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:22:19 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 10:13:36 by rguigneb         ###   ########.fr       */
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
	if (game->entities == entity)
		game->entities = NULL;
	else
	{
		tmp = game->entities;
		while (tmp->next != entity)
			tmp = tmp->next;
		tmp->next = entity->next;
	}
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

void	entities_loop(t_game *game)
{
	t_entity	*current;
	t_vec2		pos;

	if (!game)
		return ;
	current = game->entities;
	while (current)
	{
		pos = get_to_world_coord(game, current->pos.x , current->pos.y);
		pos.x += get_min_x(game);
		pos.x -= game->camera_offsets.x;
		pos.y -= game->camera_offsets.y;
		pos.x -= current->texture.img->width / 2;
		render_asset(game, current->texture, pos);
		current = current->next;
	}
}
