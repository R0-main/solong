/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:08:24 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/10 16:55:20 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "limits.h"
#include "path_finding.h"
#include "path_finding_utils.h"

t_path	*find_path(t_vec2 pos, t_vec2 to)
{
	t_node	*first;
	t_node	*current;
	t_path	*path_to_follow;

	first = NULL;
	create_node_tree(&first, pos, pos, to);
	if (!first)
		return (NULL);
	current = first;
	path_to_follow = NULL;
	printf("%d \n", current->neighbors[UP]);
	exit(1);
	path_backtracking(&path_to_follow, path_to_follow, current);
	print_path(path_to_follow);
	free_nodes(first);
	return (path_to_follow);
}
