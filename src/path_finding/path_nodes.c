/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:13:27 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 08:35:36 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_finding.h"
#include "path_finding_utils.h"

void	free_path_nodes(t_path *first)
{
	if (first)
	{
		free_path_nodes(first->next);
		free(first);
	}
}

t_path	*create_path_node(t_path *first_path_node, t_node *first_node)
{
	t_path	*path;

	path = (t_path *)malloc(sizeof(t_path));
	if (!path)
	{
		free_path_nodes(first_path_node);
		free_nodes(first_node);
		exit_error("failed to create a path node");
		return (NULL);
	}
	path->direction = -1;
	path->next = NULL;
	path->prev = NULL;
	return (path);
}

t_path	*create_path_from_last_node(t_node *first_node, t_node *last_node)
{
	t_path	*path;

	path = create_path_node(path, first_node);
	while (last_node)
	{
		if (last_node->prev_direction != -1)
		{
			path->direction = last_node->prev_direction;
			path->prev = create_path_node(path, first_node);
			path->prev->next = path;
			if (last_node->prev && !last_node->prev->prev)
			{
				free(path->prev);
				path->prev = NULL;
			}
			else
				path = path->prev;
		}
		last_node = last_node->prev;
	}
	free_nodes(first_node);
	return (path);
}

void	print_path(t_path *path)
{
	if (!path)
		return ;
	while (path)
	{
		if (path->direction == UP)
			printf("UP\n");
		if (path->direction == DOWN)
			printf("DOWN\n");
		if (path->direction == RIGHT)
			printf("RIGHT\n");
		if (path->direction == LEFT)
			printf("LEFT\n");
		if (path->direction == -1)
			printf("ERROR\n");
		if (path->direction == -2)
			printf("ERROR@\n");
		path = path->next;
	}
}