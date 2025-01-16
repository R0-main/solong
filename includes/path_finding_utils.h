/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:08:33 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/16 09:24:10 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_FINDING_UTILS_H

# define PATH_FINDING_UTILS_H

# include "game.h"
# include "path_finding.h"
# include "utils.h"

// -----------------------------------------
//
//    Nodes Section
//
// -----------------------------------------

t_node	*create_node(t_node *first, t_vec2 pos, t_vec2 target,
			unsigned long dest_o);
void	free_nodes(t_node *first);
t_node	*get_cheapest_node(t_node *first);
void	foreach_neighbor(t_node **first, t_node **current, t_vec2 to,
			unsigned long distance_from_origin);
bool	already_a_node(t_node *first, t_vec2 pos);
void	add_to_list(t_node *prev, t_node *node);
bool	pass_through_all(t_node *first);

// -----------------------------------------
//
//    Path Section
//
// -----------------------------------------

void	print_path(t_path *path);
t_path	*create_path_node(t_path *first_path_node, t_node *first_node);
t_path	*create_path_from_last_node(t_node *first_node, t_node *last_node);

#endif
