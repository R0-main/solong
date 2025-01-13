/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:08:33 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/13 13:19:11 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_FINDING_UTILS_H

# define PATH_FINDING_UTILS_H
# include "game.h"
# include "path_finding.h"

t_node		*create_node(t_node *first, t_vec2 pos, t_vec2 target,
				unsigned long dest_o);
void		free_nodes(t_node *first);

t_path		*create_path_node(t_path *first_path_node, t_node *first_node);
void		print_path(t_path *path);

bool		is_wall(t_map *map, t_vec2 pos);

void		foreach_neighbor(t_node **first, t_node **current, t_vec2 to,
				unsigned long distance_from_origin);

#endif
