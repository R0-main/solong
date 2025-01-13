/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:32:21 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/13 08:57:26 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H

# include "mlx.h"
# include "mlx_int.h"
# include "mlx_wrapper.h"
# include "utils.h"
# include <math.h>
# include <stdbool.h>
# include <time.h> // TODO : REMOVE

typedef enum s_map_element
{
	WALL = '1',
	FLOOR = '0',
	PLAYER = 'P',
	EXIT = 'E',
	COLLECTIBLE = 'C',
}								t_map_element;

int								game_init(t_mlx *mlx);

typedef struct s_vec2
{
	int							x;
	int							y;
}								t_vec2;

bool							is_same_position(t_vec2 pos1, t_vec2 pos2);
bool							is_between(t_vec2 pos, t_vec2 bpos1,
									t_vec2 bpos2);
bool							fast_is_between(t_vec2 pos, t_vec2 bpos1,
									t_vec2 bpos2);
bool							is_between_zero_and(t_vec2 pos, t_vec2 to);
bool							is_between_one(int pos, int bpos1, int bpos2);
unsigned long					distance_between(t_vec2 pos1, t_vec2 pos2);
// MAP
typedef struct s_map
{
	char						**buffer;
	int							height;
	int							width;
	t_vec2						player_spawnpoint;
	t_vec2						exit_coords;
	t_img						*map_img;
	t_img_data					map_img_data;
}								t_map;

typedef struct s_rendering_element
{
	t_vec2						position;
	t_img						*img;
	t_img_data					img_data;
	struct s_rendering_element	*next;
}								t_rendering_element;

typedef struct s_game
{
	t_vec2						camera_offsets;
	t_vec2						last_mouse_location;
	t_img						*rendering_buffer;
	t_img_data					rendering_buffer_data;
	t_mlx						*mlx;
	t_map						*map;
	t_rendering_element			*rendering_queue;
}								t_game;

typedef struct s_texture
{
	t_img						*img;
	t_img_data					img_data;
}								t_texture;

# include "animations.h"
# include "rendering.h"
# include "textures.h"

t_game							*get_game_instance(void);
void							process_next_frame(void);
void							render_next_frame(t_mlx *mlx);

void							parse_map(char *path);
t_map							*get_map(void);
int								free_map(void);
void							print_map(void);
int								draw_bg(t_game *game);

// KEYBINDS
void							on_key_pressed(int key);

// WORLD
int								get_max_x(t_game *game);
int								get_max_y(t_game *game);
int								get_min_y(t_game *game);
int								get_min_x(t_game *game);
t_vec2							get_to_world_coord(t_game *game, int x, int y);

int								init_map_asset(t_game *game);

# define POSITION_ZERO ((t_vec2){0, 0})
# define POSITION_MAX ((t_vec2){WIDTH, HEIGHT})

#endif
