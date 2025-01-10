/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_backtracking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:22:02 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/10 09:36:46 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_finding.h"
#include "path_finding_utils.h"

void	inspect_all(t_node *first)
{
	if (!first)
		return ;
	if (first)
		first->inspected = true;
	inspect_all(first->down);
	inspect_all(first->up);
	inspect_all(first->left);
	inspect_all(first->right);
}

t_direction	get_most_efficient(t_node *c)
{
	long		min;
	t_direction	direction;
	t_node		*target;

	target = c->down;
	min = 0;
	direction = -1;
	if (target && !target->inspected && target->path_cost > min)
	{
		min = target->path_cost;
		direction = DOWN;
	}
	target = c->up;
	if (target && !target->inspected && target->path_cost > min)
	{
		min = target->path_cost;
		direction = UP;
	}
	target = c->right;
	if (target && !target->inspected && target->path_cost > min)
	{
		min = target->path_cost;
		direction = RIGHT;
	}
	target = c->left;
	if (target && !target->inspected && target->path_cost > min)
	{
		min = target->path_cost;
		direction = LEFT;
	}
	return (direction);
}

void	path_backtracking(t_path *path, t_node *current)
{
	t_direction	direction;
	t_node		*next;

	if (!current || !path || all_inspected(current))
		return ;
	current->inspected = true;
	if (current->is_taget)
	{
		inspect_all(current);
		return ;
	}
	direction = get_most_efficient(current);
	if (direction == -1)
	{
		if (!path->prev)
			path->prev = path;
		if (!current->prev)
			current->prev = current;
		path_backtracking(path->prev, current->prev);
		return ;
	}
	if (direction == UP)
	{
		next = current->up;
		path->direction = UP;
	}
	else if (direction == DOWN)
	{
		next = current->down;
		path->direction = DOWN;
	}
	else if (direction == RIGHT)
	{
		next = current->right;
		path->direction = RIGHT;
	}
	else if (direction == LEFT)
	{
		next = current->left;
		path->direction = LEFT;
	}
	next->prev = current;
	path->next = create_path_node(path);
	path->next->prev = path;
	path_backtracking(path->next, next);
}
