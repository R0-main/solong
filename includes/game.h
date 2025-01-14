/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:32:21 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 08:52:37 by rguigneb         ###   ########.fr       */
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

int								game_init(t_mlx *mlx);

typedef struct s_vec2
{
	int							x;
	int							y;
}								t_vec2;

typedef struct s_vec2_list
{
	int							x;
	int							y;
	t_vec2						*next;
}								t_vec2_list;

bool							is_same_position(t_vec2 pos1, t_vec2 pos2);
bool							is_between(t_vec2 pos, t_vec2 bpos1,
									t_vec2 bpos2);
bool							fast_is_between(t_vec2 pos, t_vec2 bpos1,
									t_vec2 bpos2);
bool							is_between_zero_and(t_vec2 pos, t_vec2 to);
unsigned long					distance_between(t_vec2 pos1, t_vec2 pos2);

# define MAX_COLLECTIBLE 999

// MAP
typedef struct s_map
{
	char						**buffer;
	int							height;
	int							width;
	t_vec2						player_spawnpoint;
	t_vec2						exit_coords;
	t_vec2						collectibles_coords[MAX_COLLECTIBLE];
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

# define MAP_SPAWN_POINT_ERROR "map has more than 1 player spawn point or doesn't have any!"
# define MAP_EXIT_ERROR "map has more than 1 exit or doesn't have any!"
# define MAP_COLLECTIBLE_ERROR "map doesn't have any collectible!"
# define MAP_WIDTH_ERROR "map width is not the same everywhere!"
# define MAP_LEFT_OR_AND_RIGHT_BORDER_ERROR "map doesn't have left or/and right border(s)!"
# define MAP_UPPER_OR_AND_BOTTOM_BORDER_ERROR "map doesn't have upper or/and bottom border(s)!"
# define MAP_NOT_ALLOWED_CHARS_ERROR "map doesn't have only allowed chars!"
# define MAP_MAX_COLLECTIBLE_ERROR "You cannot have more than MAX_COLLECTIBLE collectibles"
# define MAP_PLAYER_CANNOT_EXIT_ERROR "player cannot exit the map!"
# define MAP_PLAYER_CANNOT_ACCESS_ALL_COLLECTIBLE_ERROR "player cannot access all collectibles!"
# define MAP_IS_NOT_RECTANGLE_ERROR "map is not a rectangle!"

# define MAP_CANNOT_OPEN_FILE_ERROR "cannot open map file!"
# define MAP_MALLOC_FAILED_ERROR "map malloc failed!"

# define MAP_BUFFER_ERROR "no map buffer provided at check_valid_map!"
# define MAP_WIDTH_OR_AND_HEIGHT_ERROR "map height or/and width are negative in check_valid_map!"

void							check_for_possible_paths(t_map *map);

typedef struct s_map_needed_objects
{
	int							exit_count;
	int							player_count;
	int							collectible_count;
}								t_map_needed_objects;

void							check_for_duplicate_point(t_map *map);
void							check_map_borders(t_map *map);
void							setup_map_coords(t_map *map);

typedef enum s_map_element
{
	WALL = '1',
	FLOOR = '0',
	PLAYER = 'P',
	EXIT = 'E',
	COLLECTIBLE = 'C',
}								t_map_element;

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
