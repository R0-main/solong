/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ticks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:43:33 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 16:57:15 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

bool	handle_path_finding(t_game *game, t_entity *entity)
{
	t_vec2	pos;
	t_path	*path;

	if (!entity->path_to_follow)
		return (false);
	pos = entity->pos;
	if (entity->path_to_follow->direction == UP)
		pos.y -= 1;
	if (entity->path_to_follow->direction == DOWN)
		pos.y += 1;
	if (entity->path_to_follow->direction == RIGHT)
		pos.x += 1;
	if (entity->path_to_follow->direction == LEFT)
		pos.x -= 1;
	if (!is_wall(game->map, pos))
	{
		path = entity->path_to_follow;
		entity->last_direction = entity->path_to_follow->direction;
		entity->path_to_follow = entity->path_to_follow->next;
		if (entity->type == PLAYER_TYPE)
			game->steps_made += 1;
		return (free(path), path = NULL, entity->pos = pos, true);
	}
	else
		return (free_path_nodes(entity->path_to_follow), false);
}

void	on_game_tick(t_game *game)
{
	t_entity	*current;
	t_vec2		pos;
	t_path		*path;

	if (!game || !game->init)
		return ;
	current = game->entities;
	if (game->tick % 20 == 0)
	{
		while (current)
		{
			handle_path_finding(game, current);
			current = current->next;
		}
	}
}