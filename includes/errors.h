/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:51:17 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 14:20:02 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H

# define ERRORS_H

// -----------------------------------------
//
//    Errors Section
//
// -----------------------------------------

# define MAP_SPAWN_POINT_ERROR "map has more than 1 \
player spawn point or doesn't have any!"
# define MAP_EXIT_ERROR "map has more than 1 exit or doesn't have any!"
# define MAP_COLLECTIBLE_ERROR "map doesn't have any collectible!"
# define MAP_WIDTH_ERROR "map width is not the same everywhere!"
# define MAP_LEFT_OR_AND_RIGHT_BORDER_ERROR "map doesn't have \
left or/and right border(s)!"
# define MAP_UPPER_OR_AND_BOTTOM_BORDER_ERROR "map doesn't have upper \
or/and bottom border(s)!"
# define MAP_NOT_ALLOWED_CHARS_ERROR "map doesn't have only allowed chars!"
# define MAP_MAX_COLLECTIBLE_ERROR "You cannot have more than \
MAX_COLLECTIBLES collectibles"
# define MAP_MAX_ENEMY_ERROR "You cannot have more than MAX_ENEMIES enemies"
# define MAP_PLAYER_CANNOT_EXIT_ERROR "player cannot exit the map!"
# define MAP_PLAYER_CANNOT_ACCESS_ALL_COLLECTIBLE_ERROR "player cannot \
access all collectibles!"
# define MAP_IS_NOT_RECTANGLE_ERROR "map is not a rectangle!"

# define MAP_CANNOT_OPEN_FILE_ERROR "cannot open map file!"
# define MAP_MALLOC_FAILED_ERROR "map malloc failed!"

# define MAP_BUFFER_ERROR "no map buffer provided at check_valid_map!"
# define MAP_WIDTH_OR_AND_HEIGHT_ERROR "map height or/and width are \
negative in check_valid_map!"

# define GAME_RENDERING_BUFFER_MALLOC_FAILED "game rendering \
buffer malloc failed!"

# define ENTITIES_MALLOC_FAILED "malloc fails during entity creation!"

# define ENTITIES_FIND_EXIT_ENTITY "cannot find exit entity \
after collected all collectible"

# define MLX_WINDOW_ERROR "mlx window creation failed"
# define MLX_ERROR "mlx creation failed"

# define MAP_FILE_EXTENSION_ERROR "map file is not in .ber"
# define MAIN_TOO_MANY_ARGS "too many arguments!"
# define MAIN_NO_ARG "Please provide a map in .ber"

void	exit_error(const char *msg);

// -----------------------------------------
//
//    Log Section
//
// -----------------------------------------

# define GAME_WON_LOG "well played, you have finally collected all \
the coins and reached the exit!"
# define GAME_OVER_LOG "game over, you have been captured by an evil monster!"
# define GAME_LEAVE_LOG "you closed the game without finishing it!"

void	exit_log(const char *msg);

#endif
