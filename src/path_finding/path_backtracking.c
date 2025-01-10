/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_backtracking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:22:02 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/10 16:35:48 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_finding.h"
#include "path_finding_utils.h"

void	*inspect_all(t_node *first)
{
	if (!first)
		return (NULL);
	first->inspected = true;
	inspect_all(first->neighbors[UP]);
	inspect_all(first->neighbors[DOWN]);
	inspect_all(first->neighbors[RIGHT]);
	inspect_all(first->neighbors[LEFT]);
	return (NULL);
}

t_direction	get_most_efficient(t_node *c)
{
	unsigned long	min;
	t_direction		direction;
	t_direction		i;

	min = c->path_cost - 1;
	direction = -1;
	i = UP;
	while (i <= LEFT)
	{
		if (c->neighbors[i] && !c->neighbors[i]->inspected
			&& c->neighbors[i]->path_cost < min)
		{
			min = c->neighbors[i]->path_cost;
			direction = i;
		}
		i++;
	}
	return (direction);
}

void	*path_backtracking(t_path **first, t_path *path, t_node *c)
{
	t_direction	direction;
	t_node		*next;
	t_path		*new;

	if (!c)
		return (NULL);
	c->inspected = true;
	if (c->is_taget)
	{
		print_path(*first);
		exit_error("target found !");
		return (inspect_all(c));
	}
	if (all_inspected(c))
		return (NULL);
	if (!path)
	{
		printf("created !\n\n\n\\n\n");
		path = create_path_node(path);
		*first = path;
	}
	direction = get_most_efficient(c);
	printf("direction : %d\n", direction);
	if (direction == -1)
	{
		new = path->prev;
		free(path);
		path_backtracking(first, new, c->prev);
		return (NULL);
	}
	c->neighbors[direction]->prev = c;
	path->next = create_path_node(first);
	path->direction = direction;
	path_backtracking(first, path->next, c->neighbors[direction]);
}
