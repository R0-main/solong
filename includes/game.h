/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:32:21 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/10 15:17:14 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H

# include "mlx.h"
# include "mlx_int.h"
# include "mlx_wrapper.h"

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

typedef struct s_game
{
	t_coordinates	camera_offsets;
	t_img			*rendering_buffer;
	t_mlx			*mlx;
	t_map			*map;
	t_img			*map_img;
}					t_game;

# include "textures.h"

t_game				*get_game_instance(void);
void				process_next_frame(void);
void				render_next_frame(t_mlx *mlx);

int					parse_map(char *path);
t_map				*get_map(void);
int					free_map(void);
void				print_map(void);
int					draw_bg(t_game *game);

// KEYBINDS
void				on_key_pressed(int key);

#endif
