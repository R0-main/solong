/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:14:54 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/15 12:25:23 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "path_finding.h"
#include "path_finding_utils.h"

t_node	*create_node(t_node *first, t_vec2 pos, t_vec2 target,
		unsigned long dest_o)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
	{
		free_nodes(first);
		exit_error("failed to create a node");
		return (NULL);
	}
	node->distance_from_destination = distance_between(pos, target);
	node->distance_from_origin = dest_o;
	node->passed = false;
	node->next = NULL;
	node->cost = node->distance_from_destination + node->distance_from_origin;
	node->neighbors[UP] = (t_vec2){pos.x, pos.y - 1};
	node->neighbors[DOWN] = (t_vec2){pos.x, pos.y + 1};
	node->neighbors[RIGHT] = (t_vec2){pos.x + 1, pos.y};
	node->neighbors[LEFT] = (t_vec2){pos.x - 1, pos.y};
	node->prev = NULL;
	node->prev_direction = -1;
	node->f_score = ULONG_MAX;
	node->pos = pos;
	return (node);
}

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

void	free_nodes(t_node *node)
{
	t_node	*tmp;

	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
}
