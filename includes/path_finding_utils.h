/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:08:33 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/13 12:28:28 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_FINDING_UTILS_H

# define PATH_FINDING_UTILS_H
# include "game.h"
# include "path_finding.h"

void		set_neightbors(t_node **first, t_vec2 pos, t_node *node, t_vec2 to);

t_node		*create_node_tree(t_node **first, t_vec2 pos, t_vec2 original,
				t_vec2 to);

bool		all_inspected(t_node *c);
t_node		*create_node(t_node *first, t_vec2 pos, t_vec2 target,
				unsigned long dest_o);
void		free_nodes(t_node *first);

t_path		*create_path_node(t_path *first_path_node, t_node *first_node);
void		print_path(t_path *path);

t_direction	get_most_efficient(t_node *c);
void		*path_backtracking(t_path **first, t_path *path, t_node *current);
void		*inspect_all(t_node *first);

bool		is_wall(t_map *map, t_vec2 pos);

#endif
