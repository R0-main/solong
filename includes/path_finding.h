/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:08:33 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/13 13:06:28 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_FINDING_H

# define PATH_FINDING_H
# include "game.h"
# include <stdbool.h>
# include <stdlib.h>

typedef enum e_directions
{
	UP,
	DOWN,
	RIGHT,
	LEFT
}					t_direction;

typedef struct s_path
{
	t_direction		direction;
	struct s_path	*prev;
	struct s_path	*next;
}					t_path;

typedef struct s_node
{
	unsigned long	distance_from_destination;
	unsigned long	distance_from_origin;
	unsigned long	cost;
	unsigned long	f_score;
	bool			passed;
	t_vec2			neighbors[4];
	t_vec2			pos;
	struct s_node	*next;
	struct s_node	*prev;
	t_direction		prev_direction;
}					t_node;

void				free_path_nodes(t_path *first);
t_path				*find_path(t_vec2 pos, t_vec2 to);
void				print_path(t_path *path);
t_path				*A_star(t_vec2 from, t_vec2 to);

#endif