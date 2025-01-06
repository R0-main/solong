/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:01:51 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/06 10:27:48 by rguigneb         ###   ########.fr       */
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

int	get_max_x(t_game *game)
{
	t_coordinates	maxCoords;
	t_coordinates	maxCoords1;

	maxCoords = get_to_world_coord(game->map->witdh, 0);
	maxCoords1 = get_to_world_coord(0, game->map->height);

	if (maxCoords1.x > 0)
		return (ft_abs(maxCoords1.x) - maxCoords.x);
	else
		return (maxCoords.x - maxCoords1.x);
}

int	get_min_x(t_game *game)
{
	t_coordinates	maxCoords;

	maxCoords = get_to_world_coord(1, game->map->height);

	return (ft_abs(maxCoords.x));
}

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

	i = 0;
	x = 0;
	y = 0;
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
	x = game->map->height;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->witdh)
		{
			coords = get_to_world_coord(x, y);
			// coords.x = ((coords.x - TILE_X / 2) + (game->map->witdh * TILE_X)
			// 		/ 2);
			coords.x += get_min_x(game);
			put_img_to_into_img(map, img, coords.x, coords.y);
			x += 1;
		}
		y += 1;
	}
}

int	init_map_img(t_game *game)
{
	t_img			*map;
	int				i;
	t_coordinates	lenX;
	t_coordinates	lenX1;
	t_coordinates	lenY;

	lenX = get_to_world_coord(game->map->witdh, 0);
	lenX1 = get_to_world_coord(0, game->map->height);
	lenY = get_to_world_coord(game->map->witdh, game->map->height);
	printf("%d | %d \n", lenX.x, lenX1.x);
	map = mlx_new_image(game->mlx->mlx, get_max_x(game) + TILE_X, lenY.y
			+ TILE_Y * 0.5);
	generate_tiles(game, map);
	// exit(1);
	// map = NULL;
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
	// Début de la mesure
	start = clock();
	(void)mlx;
	game = get_game_instance();
	mlx_destroy_image(game->mlx->mlx, game->rendering_buffer);
	game->rendering_buffer = mlx_new_image(game->mlx->mlx, WIDTH, HEIGHT);
	if (!game->rendering_buffer)
		return ;
	draw_map(game);
	render_asset(game, get_texture(PLAYER_TEXTURE), (t_coordinates){100
		+ game->camera_offsets.x, 100 + game->camera_offsets.y});
	proccess_rendering_buffer(game);
	mlx_put_image_to_window(mlx->mlx, mlx->win, game->rendering_buffer, 0, 0);
	// Calcul du temps écoulé en millisecondes
	end = clock();
	time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
	if (time_taken > max && max != 0)
	{
		max = time_taken;
	}
	if (max == 0)
		max += 0.01;
	printf("Temps d'exécution : %.3f ms | max : %.3f ms | fps : %.0f\n",
		time_taken, max, 1000 / time_taken);
}
