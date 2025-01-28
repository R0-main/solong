/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:01:51 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/28 09:23:23 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"
#include "rendering.h"

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
	while (t.y < HEIGHT)
	{
		t.x = 0;
		while (t.x < WIDTH)
		{
			t.pixel = ((t.y + game->camera_offsets.y) * t.d) + (t.x
					+ game->camera_offsets.x);
			if (is_between_zero_and((t_vec2){t.x + game->camera_offsets.x, t.y
					+ game->camera_offsets.y}, t.length)
				&& t.map_buffer[t.pixel] != 0)
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
	while (y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			if (game->map->buffer[y][x] == '1')
				continue ;
			coords = get_to_world_coord(x, y);
			coords.x += get_min_x(game);
			put_img_to_into_img(map, texture.img, coords);
		}
		y += 1;
	}
}

int	init_map_img(t_game *game)
{
	t_img	*map;

	map = mlx_new_image(game->mlx->mlx, get_max_x(game), get_max_y(game));
	generate_tiles(game, map);
	game->map->map_img = map;
	add_asset(MAP, map);
	return (0);
}
