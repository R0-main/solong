/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:14:54 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/10 11:51:58 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_finding.h"
#include "path_finding_utils.h"

bool	all_inspected(t_node *node)
{
	if (!node)
		return (true);
	if (node->neightbors[DOWN] && !node->neightbors[DOWN]->inspected)
		return (false);
	if (node->neightbors[UP] && !node->neightbors[UP]->inspected)
		return (false);
	if (node->neightbors[RIGHT] && !node->neightbors[RIGHT]->inspected)
		return (false);
	if (node->neightbors[LEFT] && !node->neightbors[LEFT]->inspected)
		return (false);
	if (node->inspected)
		return (true);
	return (true);
}

t_node	*create_node(t_node *first)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
	{
		free_nodes(first);
		exit_error("failed to create a node");
		return (NULL);
	}
	node->neightbors[DOWN] = NULL;
	node->neightbors[UP] = NULL;
	node->neightbors[RIGHT] = NULL;
	node->neightbors[LEFT] = NULL;
	node->path_cost = 0;
	node->inspected = false;
	node->prev = NULL;
	node->is_taget = false;
	return (node);
}

void	free_nodes(t_node *node)
{
	if (!node)
		return ;
	free_nodes(node->neightbors[UP]);
	free_nodes(node->neightbors[DOWN]);
	free_nodes(node->neightbors[RIGHT]);
	free_nodes(node->neightbors[LEFT]);
	if (node)
		free(node);
}
