/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_backtracking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:22:02 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/10 11:52:44 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_finding.h"
#include "path_finding_utils.h"

void	*inspect_all(t_node *first)
{
	if (!first)
		return (NULL);
	if (first)
		first->inspected = true;
	inspect_all(first->neightbors[UP]);
	inspect_all(first->neightbors[DOWN]);
	inspect_all(first->neightbors[RIGHT]);
	inspect_all(first->neightbors[LEFT]);
	return (NULL);
}

t_direction	get_most_efficient(t_node *c)
{
	unsigned long	min;
	t_direction		direction;
	t_direction		i;

	min = c->path_cost - 100;
	direction = -1;
	i = UP;
	while (i <= LEFT)
	{
		if (c->neightbors[i] && !c->neightbors[i]->inspected
			&& c->neightbors[i]->path_cost < min)
		{
			min = c->neightbors[i]->path_cost;
			direction = i;
		}
		i++;
	}
	return (direction);
}

void	*path_backtracking(t_path *path, t_node *c)
{
	t_direction	direction;
	t_node		*next;

	if (!c || !path || all_inspected(c))
		return (NULL);
	c->inspected = true;
	if (c->is_taget)
		return (inspect_all(c));
	direction = get_most_efficient(c);
	if (direction == -1)
	{
		if (!path->prev)
			path->prev = path;
		if (!c->prev)
			c->prev = c;
		path_backtracking(path->prev, c->prev);
		return (NULL);
	}
	next = c->neightbors[direction];
	path->direction = direction;
	next->prev = c;
	path->next = create_path_node(path);
	path->next->prev = path;
	path_backtracking(path->next, next);
}
