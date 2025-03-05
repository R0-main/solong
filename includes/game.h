/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:32:21 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 14:18:53 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H

# include "entities.h"
# include "errors.h"
# include "mlx.h"
# include "mlx_int.h"
# include "mlx_wrapper.h"
# include "rendering.h"
# include "utils.h"
# include <math.h>
# include <stdbool.h>
# include <time.h>

// -----------------------------------------
//
//    Map Section
//
// -----------------------------------------

# define MAX_COLLECTIBLES 999
# define MAX_ENEMIES 999

typedef struct s_map
{
	char							**buffer;
	int								height;
	int								width;
	t_vec2							player_spawnpoint;
	t_vec2							exit_coords;
	t_vec2							collectibles_coords[MAX_COLLECTIBLES];
	t_vec2							enemies_coords[MAX_ENEMIES];
	t_img							*map_img;
	t_img_data						map_img_data;
	unsigned int					collectible_count;
}									t_map;

typedef enum s_map_element
{
	WALL = '1',
	FLOOR = '0',
	PLAYER = 'P',
	EXIT = 'E',
	COLLECTIBLE = 'C',
	ENEMY = 'X',
}									t_map_element;

typedef struct s_map_needed_objects
{
	int								exit_count;
	int								player_count;
}									t_map_needed_objects;

void								check_for_possible_paths(t_map *map);
void								check_for_duplicate_point(t_map *map);
void								check_map_borders(t_map *map);
void								setup_map_coords(t_map *map);

void								process_next_frame(void);
void								render_next_frame(t_mlx *mlx);

void								parse_map(char *path);
t_map								*get_map(void);
int									free_map(void);
void								print_map(void);
bool								is_wall(t_map *map, t_vec2 pos);
bool								is_enemy(t_map *map, t_vec2 pos);

// -----------------------------------------
//
//    Keybinds Section
//
// -----------------------------------------

# define ESC_KEY 65307
# define LEFT_ARROW_KEY 65361
# define RIGHT_ARROW_KEY 65363
# define UP_ARROW_KEY 65362
# define DOWN_ARROW_KEY 65364
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define W_KEY 119

void								on_key_pressed(int key);
int									handle_key(int keycode, t_mlx *mlx);

void								handle_pressed_mouse_event(int key,
										t_mlx *mlx);
void								handle_release_mouse_event(int x, int y,
										t_mlx *mlx);
void								handle_mouse_motion_event(int x, int y,
										t_mlx *mlx);

// -----------------------------------------
//
//    Game Section
//
// -----------------------------------------

typedef struct s_rendering_element	t_rendering_element;

typedef struct s_game
{
	t_vec2							camera_offsets;
	t_vec2							last_mouse_location;
	t_img							*rendering_buffer;
	t_img_data						rendering_buffer_data;
	t_mlx							*mlx;
	t_map							*map;
	t_rendering_element				*rendering_queue;
	t_entity						*entities;
	unsigned int					tick;
	unsigned int					collected_collectible;
	unsigned long					steps_made;
	bool							init;
}									t_game;

void								game_init(t_mlx *mlx);
int									init_map_img(t_game *game);
void								on_game_tick(t_game *game);
t_game								*get_game_instance(void);
void								write_score_on_screen(t_game *game);

// -----------------------------------------
//
//    World Section
//
// -----------------------------------------

int									get_max_x(t_game *game);
int									get_max_y(t_game *game);
int									get_min_y(void);
int									get_min_x(t_game *game);
t_vec2								get_to_world_coord(int x, int y);
bool								is_same_position(t_vec2 pos1, t_vec2 pos2);
bool								is_between(t_vec2 pos, t_vec2 bpos1,
										t_vec2 bpos2);
bool								fast_is_between(t_vec2 pos, t_vec2 bpos1,
										t_vec2 bpos2);
bool								is_between_zero_and(t_vec2 pos, t_vec2 to);
unsigned long						distance_between(t_vec2 pos1, t_vec2 pos2);
t_vec2								get_to_tile_coord(t_game *game, int x,
										int y);

#endif
