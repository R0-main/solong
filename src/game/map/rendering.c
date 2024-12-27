/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:01:51 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/27 14:48:39 by rguigneb         ###   ########.fr       */
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

int	reset_bg(t_game *game)
{
	t_img	*img;

	img = get_texture(BLACK_SCREEN_TEXTURE);
	put_img_to_rendering_buffer(game, img, 0, 0);
	return (0);
}

int	draw_map(t_game *game)
{
	t_img			*img;
	// t_img			*map;
	int				y;
	int				x;
	t_coordinates	coords;
	int i;

	i = 0;
	y = 0;
	// map = mlx_new_image(game->mlx->mlx, game->map->witdh * TILE_X, game->map->height * TILE_Y);
	// printf("height : %d\n", game->rendering_buffer->height);
	img = get_texture(TILE_TEXTURE);
	while (y < game->rendering_buffer->height)
	{
		x = 0;
		while (x < game->rendering_buffer->width)
		{
			coords = get_to_world_coord(x + game->camera_offsets.x, y + game->camera_offsets.y);
			coords.x = ((coords.x + TILE_X / 2) + (game->map->witdh * TILE_X)
					/ 2);
			// coords.x += TILE_X;
			// coords.y += TILE_Y;
			// goofy :  && coords.y < HEIGHT - TILE_Y
			//  printf("coords : %d %d\n", coords.x, coords.y);
			put_img_to_into_img(game->rendering_buffer, img, coords.x, coords.y );
			i++;
			x += TILE_X;
		}
		y += TILE_Y;
	}
	printf("total loop : %d\n", i);
	// game->map_img = map;
	// add_asset(MAP, map);
	return (0);
}

int	init_map_img(t_game *game)
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
			x += 1;
		}
		y += 1;
	}
	game->map_img = map;
	add_asset(MAP, map);
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
				put_img_to_rendering_buffer(game, img, coords.x, coords.y);
			// if (coords.x <= 0 && coords.y < HEIGHT - TILE_Y)
			x += 1;
		}
		y += 1;
	}
	return (0);
}

// static char *get_pixel(t_img *asset, t_coordinates coords)
// {
// 	return (&(asset->data[get_pixel_index(asset, coords)]));
// }

void	process_next_frame(void)
{
}

void	render_asset(t_game *game, t_img *asset, t_coordinates coords)
{
	int		x;
	int		y;
	t_img	*img;
	int		pixel;
	int		pixel_index;

	y = -1;
	img = mlx_new_image(game->mlx->mlx, asset->width, asset->height);
	if (!img)
		return;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->height)
		{
			pixel = get_pixel_index(asset, (t_coordinates){x, y});
			if (asset->data[pixel] == 0 && asset->data[pixel + 1] == 0 && asset->data[pixel + 2] == 0)
			{
				pixel_index = get_pixel_index(game->map_img, (t_coordinates){x + coords.x + (game->camera_offsets.x * TILE_X), y + coords.y + (game->camera_offsets.y * TILE_Y)});
				img->data[pixel] = game->map_img->data[pixel_index];
				img->data[pixel + 1] = game->map_img->data[pixel_index + 1];
				img->data[pixel + 2] = game->map_img->data[pixel_index + 2];
				img->data[pixel + 3] = game->map_img->data[pixel_index + 3];
			}
			else
			{
				img->data[pixel] = asset->data[pixel];
				img->data[pixel + 1] = asset->data[pixel + 1];
				img->data[pixel + 2] = asset->data[pixel + 2];
				img->data[pixel + 3] = asset->data[pixel + 3];
			}
		}
	}
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, img, coords.x, coords.y);
	mlx_destroy_image(game->mlx->mlx, img);
}

void	render_next_frame(t_mlx *mlx)
{
	clock_t start, end;
    double time_taken;

    // Début de la mesure
    start = clock();

	t_game	*game;

	(void)mlx;
	game = get_game_instance();
	(void)game;
	reset_rendering_buffer(game);
	draw_map(game);
	// put_img_to_into_img(game->rendering_buffer, game->map_img,  0, 0);
	put_img_to_into_img(game->rendering_buffer, get_texture(PLAYER_TEXTURE), 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, game->rendering_buffer,  0, 0);
	// mlx_put_image_to_window(mlx->mlx, mlx->win, game->map_img,  game->camera_offsets.x * TILE_X, game->camera_offsets.y * TILE_Y);
	// render_asset(game, get_texture(PLAYER_TEXTURE), (t_coordinates){200, 200});
    // Fin de la mesure
	// mlx_get_data_addr(game->map_img, &t, &t, &t);
    end = clock();

    // Calcul du temps écoulé en millisecondes
    time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

    printf("Temps d'exécution : %.3f ms\n", time_taken);
}
