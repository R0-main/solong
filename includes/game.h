/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:32:21 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/05 13:30:28 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H

# include "mlx_wrapper.h"
# include "textures.h"

int			game_init(t_mlx *mlx);

// MAP
typedef struct s_map
{
	char	**buffer;
	int		height;
	int		witdh;
}			t_map;

int			parse_map(char *path);
t_map		*get_map(void);
int			free_map();

#endif
