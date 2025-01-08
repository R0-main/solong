/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:01:51 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/08 12:50:58 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"
#include "rendering.h"

void	render_asset(t_game *game, t_texture asset, t_vec2 position)
{
	t_rendering_element	*r_elem;

	r_elem = create_rendering_element(asset.img, asset.img_data, position);
	add_to_rendering_proccess(r_elem, game);
}

void	render_animation(t_game *game, t_animation_frame *asset,
		t_vec2 position)
{
	t_rendering_element	*r_elem;

	r_elem = create_rendering_element(asset->texture.img,
			asset->texture.img_data, position);
	add_to_rendering_proccess(r_elem, game);
}

struct		s_draw_map_params
{
	int		y;
	int		x;
	t_vec2	length;
	int32_t	*buffer;
	int32_t	*map_buffer;
	int		pixel;
	int		c;
	int		d;
};

void	init_draw_map_data(t_game *game, struct s_draw_map_params *t)
{
	t->x = 0;
	t->y = 0;
	t->buffer = (int32_t *)game->rendering_buffer->data;
	t->map_buffer = (int32_t *)game->map->map_img->data;
	t->c = game->rendering_buffer_data.line_bytes / 4;
	t->d = game->map->map_img_data.line_bytes / 4;
	t->length = (t_vec2){
		game->map->map_img->width,
		game->map->map_img->height,
	};
}

void	draw_map(t_game *game)
{
	struct s_draw_map_params	t;

	init_draw_map_data(game, &t);
	if (!is_between(t.length, POSITION_ZERO, POSITION_MAX))
		t.length = (t_vec2){WIDTH, HEIGHT};
	while (t.y < t.length.y)
	{
		t.x = 0;
		while (t.x < t.length.x)
		{
			t.pixel = ((t.y + game->camera_offsets.y) * t.d) + (t.x
					+ game->camera_offsets.x);
			if (t.map_buffer[t.pixel] != 0)
			{
				t.buffer[(t.y * t.c) + (t.x)] = t.map_buffer[t.pixel];
				t.buffer[((t.y + 1) * t.c) + (t.x)] = t.map_buffer[t.pixel];
				t.buffer[((t.y + 1) * t.c) + (t.x + 1)] = t.map_buffer[t.pixel];
				t.buffer[(t.y * t.c) + (t.x + 1)] = t.map_buffer[t.pixel];
			}
			t.x += 2;
		}
		t.y += 2;
	}
}

void	generate_tiles(t_game *game, t_img *map)
{
	t_texture	texture;
	int			y;
	int			x;
	t_vec2		coords;

	texture = get_texture(TILE_TEXTURE);
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
			put_img_to_into_img(map, texture.img, coords);
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

// 	img = get_texture(ROCK_TEXTURE);
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

	map = mlx_new_image(game->mlx->mlx, get_max_x(game), get_max_y(game));
	generate_tiles(game, map);
	// generate_borders(game, map);
	game->map->map_img = map;
	add_asset(MAP, map);
	return (0);
}

void	render_next_frame(t_mlx *mlx)
{
	double						time_taken;
	static float				max;
	t_game						*game;
	static t_animation_frame	*coin = NULL;
	static int					i = 0;

	clock_t start, end;
	if (!coin)
		coin = get_animation_first_frame(COIN_ANIMATION);
	start = clock();
	game = get_game_instance();
	mlx_destroy_image(mlx->mlx, game->rendering_buffer);
	game->rendering_buffer = mlx_new_image(game->mlx->mlx, WIDTH, HEIGHT);
	if (!game->rendering_buffer)
		return ;
	draw_map(game);
	render_animation(game, coin, (t_vec2){15, 15});
	if (i % (100 / coin->animation.params.speed) == 0)
		coin = coin->next;
	i++;
	render_asset(game, get_texture(PLAYER_TEXTURE), (t_vec2){0
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
