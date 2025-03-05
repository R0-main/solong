/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:43:20 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 14:21:01 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	add_to_entities_list(t_entity *entity)
{
	t_entity	*tmp;
	t_game		*game;

	game = get_game_instance();
	if (!game || !game->init)
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

	if (!game || !game->init)
		return (NULL);
	current = game->entities;
	while (current)
	{
		if (is_same_position(current->pos, pos) && current->type == type)
			return (current);
		current = current->next;
	}
	return (NULL);
}

bool	move_entity(t_game *game, t_entity *entity, t_direction direction)
{
	t_vec2	pos;

	if (!entity || (int)direction == -1)
		return (false);
	pos = entity->pos;
	if (direction == UP)
		pos.y -= 1;
	if (direction == DOWN)
		pos.y += 1;
	if (direction == RIGHT)
		pos.x += 1;
	if (direction == LEFT)
		pos.x -= 1;
	if (!is_wall(game->map, pos))
	{
		entity->pos = pos;
		return (true);
	}
	return (false);
}

t_entity	*get_entity_at_location_diffrent_from(t_game *game, t_vec2 pos,
		t_entity *entity)
{
	t_entity	*current;

	if (!game || !game->init)
		return (NULL);
	current = game->entities;
	while (current)
	{
		if (is_same_position(current->pos, pos) && current != entity)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	rotate_entity_texture(t_game *game, t_entity *entity,
		t_direction direction)
{
	if (!entity || !game || !game->init)
		return ;
	if (entity->directions_textures[direction].img)
		entity->texture = entity->directions_textures[direction];
}
