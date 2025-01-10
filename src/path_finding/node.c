/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:14:54 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/10 10:50:12 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_finding.h"
#include "path_finding_utils.h"

bool	all_inspected(t_node *c)
{
	if (!c)
		return (true);
	if (c->down && !c->down->inspected)
		return (false);
	if (c->up && !c->up->inspected)
		return (false);
	if (c->right && !c->right->inspected)
		return (false);
	if (c->left && !c->left->inspected)
		return (false);
	if (c->inspected)
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
	node->down = NULL;
	node->up = NULL;
	node->left = NULL;
	node->right = NULL;
	node->path_cost = 0;
	node->inspected = false;
	node->prev = NULL;
	node->is_taget = false;
	return (node);
}

void	free_nodes(t_node *first)
{
	if (!first)
		return ;
	free_nodes(first->down);
	free_nodes(first->up);
	free_nodes(first->left);
	free_nodes(first->right);
	if (first)
		free(first);
}
