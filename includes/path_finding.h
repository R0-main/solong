/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:08:33 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/10 09:30:12 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_FINDING_H

# define PATH_FINDING_H
# include <stdbool.h>
# include <stdlib.h>
# include "game.h"

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
	long			path_cost;
	bool			inspected;
	bool			is_taget;
	struct s_node	*prev;
	struct s_node	*up;
	struct s_node	*down;
	struct s_node	*right;
	struct s_node	*left;
}					t_node;

# define S_NODE_OFFSET sizeof(t_node) - sizeof(t_node *) * 4

void				free_path_nodes(t_path *first);
t_path				*find_path(t_vec2 pos, t_vec2 to);

#endif
