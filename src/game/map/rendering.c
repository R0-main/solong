/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:01:51 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/10 16:04:39 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

// void	render_map(t_mlx *mlx)
// {
// 	int		x;
// 	int		y;
// 	t_map	*map;

// 	x = 0;
// 	y = 0;
// 	map = get_map();
// 	while (y < map->height - 1)
// 	{
// 		while (x < map->witdh - 1)
// 		{
// 		}
// 	}
// }

static t_coordinates	get_to_world_coord(int x, int y)
{
	t_coordinates	coords;

	coords.x = (x * TILE_X * 0.5) + (y * -0.5 * TILE_X);
	coords.y = (x * TILE_Y * 0.25) + (y * 0.25) * TILE_Y;
	return (coords);
}

int	reset_bg(t_game *game)
{
	t_img	*img;

	img = get_texture(BLACK_SCREEN_TEXTURE);
	put_img_to_rendering_buffer(game, img, 0, 0);
	return (0);
}

int	test_game(t_game *game)
{
	t_img			*img;
	t_img			*map;
	int				y;
	int				x;
	t_coordinates	coords;

	y = 0;
	map = mlx_new_image(game->mlx->mlx, game->map->witdh * TILE_X, game->map->height * TILE_Y);
	img = get_texture(TILE_TEXTURE);
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->witdh)
		{
			coords = get_to_world_coord(x, y);
			coords.x = ((coords.x - TILE_X / 2) + (game->map->witdh * TILE_X)
					/ 2);
			// goofy :  && coords.y < HEIGHT - TILE_Y
			put_img_to_into_img(map, img, coords.x, coords.y );
			// if (coords.x >= 0 && coords.y >= 0)
			// {
			// }
			x += 1;
		}
		y += 1;
		// if (y % (img->height * 2) == 0)
		// 	y += img->height / 2;
		// else
	}
	game->map_img = map;
	return (0);
}

int	draw_bg(t_game *game)
{
	t_img			*img;
	int				y;
	int				x;
	t_coordinates	coords;

	y = 0;
	img = get_texture(TILE_TEXTURE);
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->witdh)
		{
			coords = get_to_world_coord(x + game->camera_offsets.x, y
					+ game->camera_offsets.y);
			coords.x = ((coords.x - TILE_X / 2) + (game->map->witdh * TILE_X)
					/ 2);
			// goofy :  && coords.y < HEIGHT - TILE_Y
			put_img_to_rendering_buffer(game, img, coords.x, coords.y);
			x += 1;
		}
		y += 1;
	}
	return (0);
}

void	process_next_frame(void)
{
}

void	render_next_frame(t_mlx *mlx)
{
	t_game	*game;

	game = get_game_instance();
	reset_rendering_buffer(game);
	// mlx_clear_window(mlx->mlx, mlx->win);
	// draw_bg(game);
	mlx_clear_window(mlx->mlx, mlx->win);
	// mlx_put_image_to_window(mlx->mlx, mlx->win, get_texture(BLACK_SCREEN_TEXTURE), 0, 0);
	put_img_to_into_img(game->map_img, game->rendering_buffer, 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, game->map_img, game->camera_offsets.x * TILE_X, game->camera_offsets.y * TILE_Y);
	// mlx_put_image_to_window(mlx->mlx, mlx->win, game->rendering_buffer, 0, 0);
	// mlx_string_put(mlx->mlx, mlx->win, 50, 650, 0xFFFFFFFF,
	// 	ft_itoa(game->camera_offsets.x));
	// mlx_string_put(mlx->mlx, mlx->win, 50, 675, 0xFFFFFFFF,
	// 	ft_itoa(game->camera_offsets.y));
}
