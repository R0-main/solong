/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:32:21 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/28 13:01:19 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H

# include "math.h"
# include "mlx.h"
# include "mlx_int.h"
# include "mlx_wrapper.h"
# include <stdbool.h>
# include <time.h> // TODO : REMOVE

int								game_init(t_mlx *mlx);

typedef struct s_coordinates
{
	int							x;
	int							y;
}								t_coordinates;

bool							is_same_position(t_coordinates pos1,
									t_coordinates pos2);
bool							is_between(t_coordinates pos,
									t_coordinates bpos1, t_coordinates bpos2);

// MAP
typedef struct s_map
{
	char						**buffer;
	int							height;
	int							witdh;
	t_coordinates				player_spawnpoint;
	t_coordinates				exit_coords;
}								t_map;

typedef struct s_rendering_element
{
	t_coordinates				position;
	t_img						*img;
	struct s_rendering_element	*next;
}								t_rendering_element;

typedef struct s_game
{
	t_coordinates				camera_offsets;
	t_img						*rendering_buffer;
	t_img_data					rendering_buffer_data;
	t_mlx						*mlx;
	t_map						*map;
	t_img						*map_img;
	t_rendering_element			*rendering_queue;
}								t_game;

# include "rendering.h"
# include "textures.h"

t_game							*get_game_instance(void);
void							process_next_frame(void);
void							render_next_frame(t_mlx *mlx);

int								parse_map(char *path);
t_map							*get_map(void);
int								free_map(void);
void							print_map(void);
int								draw_bg(t_game *game);

// KEYBINDS
void							on_key_pressed(int key);

// WORLD
t_coordinates					get_to_world_coord(int x, int y);

int								init_map_asset(t_game *game);

# define POSITION_ZERO ((t_coordinates){0, 0})
# define POSITION_MAX ((t_coordinates){WIDTH, HEIGHT})

#endif
