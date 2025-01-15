/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:08:24 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/15 12:03:15 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "limits.h"
#include "path_finding.h"
#include "path_finding_utils.h"

// A* Algo
t_path	*find_path(t_vec2 from, t_vec2 to)
{
	t_node			*first;
	t_node			*current;
	unsigned long	distance_from_origin;

	distance_from_origin = 0;
	if (is_same_position(from, to))
		return (NULL);
	first = NULL;
	current = create_node(first, from, to, distance_from_origin);
	first = current;
	current->f_score = distance_between(from, to);
	while (!pass_through_all(first))
	{
		current = get_cheapest_node(first);
		if (!current)
			return (free_nodes(first), NULL);
		current->passed = true;
		if (is_same_position(current->pos, to))
			return (create_path_from_last_node(first, current));
		foreach_neighbor(&first, &current, to, distance_from_origin++);
	}
	free_nodes(first);
	return (NULL);
}
