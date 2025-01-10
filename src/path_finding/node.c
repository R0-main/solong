/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:14:54 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/10 15:53:31 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_finding.h"
#include "path_finding_utils.h"

bool	all_inspected(t_node *node)
{
	if (!node)
		return (true);
	if (node->neighbors[DOWN] && !node->neighbors[DOWN]->inspected)
		return (false);
	if (node->neighbors[UP] && !node->neighbors[UP]->inspected)
		return (false);
	if (node->neighbors[RIGHT] && !node->neighbors[RIGHT]->inspected)
		return (false);
	if (node->neighbors[LEFT] && !node->neighbors[LEFT]->inspected)
		return (false);
	return (true);
}

t_node	*create_node(t_node *first, t_vec2 pos)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
	{
		free_nodes(first);
		exit_error("failed to create a node");
		return (NULL);
	}
	node->neighbors[UP] = NULL;
	node->neighbors[DOWN] = NULL;
	node->neighbors[RIGHT] = NULL;
	node->neighbors[LEFT] = NULL;
	node->path_cost = 0;
	node->inspected = false;
	node->prev = NULL;
	node->is_taget = false;
	node->pos = pos;
	return (node);
}

void	free_nodes(t_node *node)
{
	if (!node)
		return ;
	free_nodes(node->neighbors[UP]);
	free_nodes(node->neighbors[DOWN]);
	free_nodes(node->neighbors[RIGHT]);
	free_nodes(node->neighbors[LEFT]);
	if (node)
		free(node);
}
