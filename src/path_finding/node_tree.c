/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:16:55 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/13 13:18:46 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "limits.h"
#include "path_finding.h"
#include "path_finding_utils.h"

t_node	*get_cheapest_node(t_node *first)
{
	t_node			*cheapest;
	unsigned long	cheapest_cost;

	if (!first)
		return (NULL);
	cheapest_cost = ULONG_MAX;
	cheapest = NULL;
	while (first)
	{
		if (first->passed == false)
		{
			if (first->f_score <= cheapest_cost)
			{
				cheapest_cost = first->f_score;
				cheapest = first;
			}
		}
		first = first->next;
	}
	return (cheapest);
}

bool	already_a_node(t_node *first, t_vec2 pos)
{
	while (first)
	{
		if (is_same_position(first->pos, pos))
			return (true);
		first = first->next;
	}
	return (false);
}

void	add_to_list(t_node *prev, t_node *node)
{
	if (!prev)
		return ;
	while (prev->next)
		prev = prev->next;
	prev->next = node;
	node->next = NULL;
}

bool	is_finished(t_node *first)
{
	while (first)
	{
		if (first->passed == false)
			return (false);
		first = first->next;
	}
	return (true);
}

t_path	*create_path_from_last_node(t_node *first_node, t_node *last_node)
{
	t_path	*path;
	t_path	*first;

	path = create_path_node(path, first_node);
	first = path;
	while (last_node->prev)
	{
		path->direction = last_node->prev_direction;
		path->next = create_path_node(first, first_node);
		path->next->prev = path;
		path = path->next;
		last_node = last_node->prev;
	}
	free_nodes(first_node);
	return (first);
}

