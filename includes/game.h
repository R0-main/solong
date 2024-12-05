/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:32:21 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/05 18:21:31 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H

# include "mlx_wrapper.h"
# include "textures.h"

int					game_init(t_mlx *mlx);

typedef struct s_coordinates
{
	int				x;
	int				y;
}					t_coordinates;

// MAP
typedef struct s_map
{
	char			**buffer;
	int				height;
	int				witdh;
	t_coordinates	player_spawnpoint;
	t_coordinates	exit_coords;
}					t_map;

int					parse_map(char *path);
t_map				*get_map(void);
int					free_map(void);
void				print_map(void);

#endif
