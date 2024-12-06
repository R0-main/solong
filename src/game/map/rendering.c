/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:01:51 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/06 19:58:30 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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

int	draw_bg(t_game *game)
{
	t_img			*img;
	int				y;
	int				x;
	t_coordinates	coords;

	y = 0;
	x = 0;
	(void)game;
	img = get_texture(TILE_TEXTURE);
	while (y < game->map->height)
	{
		x = 0;
		while (x <  game->map->witdh)
		{
			coords = get_to_world_coord(x, y);
			put_img_to_rendering_buffer(game, img, (coords.x - TILE_X / 2) + (game->map->witdh * TILE_X) / 2, coords.y);
			// put_img_to_rendering_buffer(game, img, x, y + 16);
			// put_img_to_rendering_buffer(game, img, x, y + 48);
			// put_img_to_rendering_buffer(game, img, x + 16, y + 64);
			// put_img_to_rendering_buffer(game, img, x + 16, y + 48);
			// mlx_put_image_to_window(mlx->mlx, mlx->win, img, y, x);
			// put_transparent_texture_on_window(TILE_TEXTURE, mlx, i, j);
			x += 1;
		}
		y += 1;
		// if (y % (img->height * 2) == 0)
		// 	y += img->height / 2;
		// else
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
	draw_bg(game);
	mlx_put_image_to_window(mlx->mlx, mlx->win, game->rendering_buffer, 0, 0);
}
