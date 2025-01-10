/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:16:55 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/10 11:50:10 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "path_finding.h"
#include "path_finding_utils.h"

void	set_node_cost(t_node *node, unsigned long i)
{
	if (!node || node->path_cost != 0)
		return ;
	node->path_cost = i;
	set_node_cost(node->neightbors[UP], i + 1);
	set_node_cost(node->neightbors[DOWN], i + 1);
	set_node_cost(node->neightbors[RIGHT], i + 1);
	set_node_cost(node->neightbors[LEFT], i + 1);
}

t_node	*create_node_tree(t_node **first, t_vec2 pos, t_vec2 to)
{
	t_node	*current;
	t_game	*game;
	t_vec2	max_map;

	game = get_game_instance();
	max_map = (t_vec2){game->map->witdh, game->map->height};
	if (!is_between_zero_and(pos, max_map))
		return (NULL);
	current = create_node(first);
	if (!*first)
		*first = current;
	if (is_same_position(pos, to))
	{
		set_node_cost(current, 1);
		current->is_taget = true;
	}
	else
		set_neightbors(first, pos, current, to);
	return (current);
}
