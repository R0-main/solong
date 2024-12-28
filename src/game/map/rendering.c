/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:01:51 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/28 18:12:08 by rguigneb         ###   ########.fr       */
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

struct		test
{
	int32_t	a;
	int32_t	b;
	int32_t	c;
	int32_t	d;
	int32_t	e;
};

int	draw_map(t_game *game)
{
	int					y;
	int					x;
	t_coordinates		coords;
	t_rendering_element	*r_elem;

	y = 0;
	while (y < game->rendering_buffer->height)
	{
		x = 0;
		int pixel = (y * game->rendering_buffer_data.line_bytes / 4) + (x);
		*(struct test *)(game->rendering_buffer->data + pixel) =
			(struct test){
				0xFFFFFFFF,
				0xFFFFFFFF,
				0xFFFFFFFF,
				0xFFFFFFFF,
				0xFFFFFFFF,
			};// while (x < game->rendering_buffer->width)
				// {
				// 	// coords = get_to_world_coord(x + game->camera_offsets.x, y
				// 	// 		+ game->camera_offsets.y);
				// 	// coords.x = ((coords.x + TILE_X / 2) + (game->map->witdh
								//  TILE_X)
				// 	// 		/ 2);
				// 	// r_elem = create_rendering_element(get_texture(TILE_TEXTURE),
				// 	// 		(t_coordinates){x, y});
				// 	// if (!r_elem)
				// 	// 	return (1);
				// 	// put_img_to_rendering_buffer(game, r_elem);
				// 	// free(r_elem);
				// 	// render_asset(game, get_texture(TILE_TEXTURE),
						// (t_coordinates){x, y});
				// 	x += 1;
				// }
		y += 1;
	}
	return (0);
}

void	render_next_frame(t_mlx *mlx)
{
	double				time_taken;
	static float		max;
	t_game				*game;
	t_rendering_element	*test;
	t_rendering_element	*test1;
	t_rendering_element	*test2;
	t_rendering_element	*test3;
	t_rendering_element	*test4;

	// t_rendering_element	*test2;
	clock_t start, end;
	// Début de la mesure
	start = clock();
	(void)mlx;
	game = get_game_instance();
	mlx_destroy_image(game->mlx->mlx, game->rendering_buffer);
	game->rendering_buffer = mlx_new_image(game->mlx->mlx, WIDTH, HEIGHT);
	if (!game->rendering_buffer)
		return ;
	// draw_map(game);
	render_asset(game, get_texture(PLAYER_TEXTURE), (t_coordinates){100
		+ game->camera_offsets.x, 100 + game->camera_offsets.y});
	// printf("height : %d\n", game->rendering_queue->position.x);
	proccess_rendering_buffer(game);
	mlx_put_image_to_window(mlx->mlx, mlx->win, game->rendering_buffer, 0, 0);
	// mlx_put_image_to_window(mlx->mlx, mlx->win, get_texture(MAP), 0, 0);
	// Calcul du temps écoulé en millisecondes
	end = clock();
	time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
	if (time_taken > max && max != 0)
	{
		max = time_taken;
	}
	if (max == 0)
		max += 0.01;
	printf("Temps d'exécution : %.3f ms | max : %.3f m\n", time_taken, max);
}
