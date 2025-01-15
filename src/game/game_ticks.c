/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ticks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:43:33 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/15 11:56:28 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

bool	handle_path_finding(t_game *game, t_entity *entity)
{
	t_path	*path;

	if (!entity->path_to_follow)
		return (false);
	if (move_entity(game, entity, entity->path_to_follow->direction))
	{
		path = entity->path_to_follow;
		entity->last_direction = entity->path_to_follow->direction;
		entity->path_to_follow = entity->path_to_follow->next;
		if (entity->type == PLAYER_TYPE)
			game->steps_made += 1;
		return (free(path), path = NULL, true);
	}
	else
		return (free_path_nodes(entity->path_to_follow), false);
}

void	on_game_tick(t_game *game)
{
	t_entity	*current;

	if (!game || !game->init)
		return ;
	current = game->entities;
	if (game->tick % 100 == 0)
	{
		while (current)
		{
			handle_path_finding(game, current);
			current = current->next;
		}
	}
}
