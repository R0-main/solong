/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:01:51 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/07 09:12:17 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"
#include "rendering.h"

void	render_asset(t_game *game, t_img *asset, t_coordinates position)
{
	t_rendering_element	*r_elem;

	r_elem = create_rendering_element(asset, position);
	add_to_rendering_proccess(r_elem, game);
}

struct t
{
	int32_t buffer;
	int32_t map_buffer;
};

int	draw_map(t_game *game)
{
	int		i;
	int		y;
	int		x;
	int32_t	*buffer;
	int32_t	*map_buffer;
	int		pixel;
	int		b_pixel;
	int		c;
	int		d;
	int		y1;
	int		x1;

	i = 0;
	x = 0;
	y = 0;
	y1 = 0;
	buffer = (int32_t *)game->rendering_buffer->data;
	map_buffer = (int32_t *)game->map->map_img->data;
	c = game->rendering_buffer_data.line_bytes / 4;
	d = game->map->map_img_data.line_bytes / 4;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel = ((y + game->camera_offsets.y) * d) + (x
					+ game->camera_offsets.x);
			if (y + game->camera_offsets.y < 0 || y
				+ game->camera_offsets.y > game->map->map_img->height)
			{
				x += 2;
				continue ;
			}
			if (x + game->camera_offsets.x < 0 || x
				+ game->camera_offsets.x > game->map->map_img->width)
			{
				x += 2;
				continue ;
			}
			b_pixel = (y * c) + (x);
			buffer[b_pixel] = map_buffer[pixel];
			b_pixel = ((y + 1) * c) + (x);
			buffer[b_pixel] = map_buffer[pixel];
			b_pixel = ((y + 1) * c) + (x + 1);
			buffer[b_pixel] = map_buffer[pixel];
			b_pixel = (y * c) + (x + 1);
			buffer[b_pixel] = map_buffer[pixel];
			x += 2;
		}
		y += 2;
	}
	return (0);
}

void	generate_tiles(t_game *game, t_img *map)
{
	t_img			*img;
	int				y;
	int				x;
	t_coordinates	coords;

	img = get_texture(TILE_TEXTURE);
	y = 0;
	while (y < game->map->height - 1)
	{
		x = -1;
		while (++x < game->map->witdh)
		{
			if (game->map->buffer[y][x] == '1')
				continue ;
			coords = get_to_world_coord(game, x, y);
			coords.x += get_min_x(game);
			put_img_to_into_img(map, img, coords.x, coords.y);
		}
		y += 1;
	}
}

// void	generate_borders(t_game *game, t_img *map)
// {
// 	t_img			*img;
// 	int				y;
// 	int				x;
// 	t_coordinates	coords;

// 	img = get_texture(ROCK);
// 	y = 0;
// 	while (y < game->map->height)
// 	{
// 		x = 0;
// 		while (x < game->map->witdh)
// 		{
// 			if (!game->map->buffer[y] && !game->map->buffer[y][x])
// 				break ;
// 			if (game->map->buffer[y][x] == '1')
// 			{
// 				coords = get_to_world_coord(game, x, y);
// 				coords.x += get_min_x(game);
// 				put_img_to_into_img(map, img, coords.x - 20, coords.y - 35);
// 				put_img_to_into_img(map, img, coords.x + 15 - 15, coords.y - 15
// 					- 15);
// 				put_img_to_into_img(map, img, coords.x + 25 - 15, coords.y - 15
// 					- 15);
// 				put_img_to_into_img(map, img, coords.x, coords.y - 15);
// 			}
// 			x += 1;
// 		}
// 		y += 1;
// 	}
// }

int	init_map_img(t_game *game)
{
	t_img	*map;
	int		i;

	map = mlx_new_image(game->mlx->mlx, get_max_x(game) + get_min_x(game) * 2
			+ TILE_X / 2, get_max_y(game) + get_min_y(game) * 2 + TILE_Y / 2);
	generate_tiles(game, map);
	// generate_borders(game, map);
	game->map->map_img = map;
	add_asset(MAP, map);
	return (0);
}

void	render_next_frame(t_mlx *mlx)
{
	double			time_taken;
	static float	max;
	t_game			*game;

	clock_t start, end;
	start = clock();
	game = get_game_instance();
	mlx_destroy_image(mlx->mlx, game->rendering_buffer);
	game->rendering_buffer = mlx_new_image(game->mlx->mlx, WIDTH, HEIGHT);
	if (!game->rendering_buffer)
		return ;
	draw_map(game);
	render_asset(game, get_texture(PLAYER_TEXTURE), (t_coordinates){0
		+ game->camera_offsets.x, 0 + game->camera_offsets.y});
	proccess_rendering_buffer(game);
	mlx_put_image_to_window(mlx->mlx, mlx->win, game->rendering_buffer, 0, 0);
	end = clock();
	time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
	if (time_taken > max && max != 0)
		max = time_taken;
	if (max == 0)
		max += 0.01;
	printf("Temps d'exécution : %.3f ms | max : %.3f ms | fps : %.0f\n",
		time_taken, max, 1000 / time_taken);
}
