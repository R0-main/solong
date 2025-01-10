/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:16:55 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/10 09:20:56 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "path_finding.h"
#include "path_finding_utils.h"

void	create_node_tree(t_node **first, t_node **current, t_vec2 pos,
		t_vec2 to, long index)
{
	t_game	*game;
	t_vec2	max_map;

	if (*current)
		return ;
	game = get_game_instance();
	max_map = (t_vec2){game->map->witdh, game->map->height};
	if (!is_between_zero_and(pos, max_map))
		return ;
	create_node(*first, current);
	(*current)->path_cost = index;
	if (!*first)
		*first = *current;
	if (is_same_position(pos, to))
	{
		(*current)->is_taget = true;
		return ;
	}
	set_neightbors(game->map, pos, *first, *current, to, index - 1);
}
