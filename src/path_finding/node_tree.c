/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:16:55 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 10:21:27 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "limits.h"
#include "path_finding.h"
#include "path_finding_utils.h"

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

bool	pass_through_all(t_node *first)
{
	while (first)
	{
		if (first->passed == false)
			return (false);
		first = first->next;
	}
	return (true);
}
