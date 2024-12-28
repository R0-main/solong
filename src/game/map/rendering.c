/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:01:51 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/28 13:05:43 by rguigneb         ###   ########.fr       */
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
		while (x < game->rendering_buffer->width)
		{
			coords = get_to_world_coord(x + game->camera_offsets.x, y
					+ game->camera_offsets.y);
			coords.x = ((coords.x + TILE_X / 2) + (game->map->witdh * TILE_X)
					/ 2);
			r_elem = create_rendering_element(get_texture(TILE_TEXTURE),
					coords);
			put_img_to_rendering_buffer(game, r_elem);
			free(r_elem);
			// render_asset(game, get_texture(TILE_TEXTURE), (coords));
			x += TILE_X;
		}
		y += TILE_Y;
	}
	return (0);
}

void	render_next_frame(t_mlx *mlx)
{
	double				time_taken;
	t_game				*game;
	t_rendering_element	*test;
	t_rendering_element	*test1;
	t_rendering_element	*test2;
	t_rendering_element	*test3;
	t_rendering_element	*test4;

	// t_rendering_element	*test2;
	clock_t start, end;
	// Début de la mesure
	(void)mlx;
	game = get_game_instance();
	mlx_destroy_image(game->mlx->mlx, game->rendering_buffer);
	game->rendering_buffer = mlx_new_image(game->mlx->mlx, WIDTH, HEIGHT);
	if (!game->rendering_buffer)
		return ;
	draw_map(game);
	render_asset(game, get_texture(PLAYER_TEXTURE), (t_coordinates){100
		+ game->camera_offsets.x, 100 + game->camera_offsets.y});
	// render_asset(game, get_texture(MAP),
		// (t_coordinates){game->camera_offsets.x, game->camera_offsets.y});
		// test2 = create_rendering_element(get_texture(PLAYER_TEXTURE),
		// 		(t_coordinates){130 + game->camera_offsets.x, 130
		// 		+ game->camera_offsets.y});
		// add_to_rendering_proccess(test2, game);
		printf("height : %d\n", game->rendering_queue->position.x);
		start = clock();
		proccess_rendering_buffer(game);
		end = clock();
		mlx_put_image_to_window(mlx->mlx, mlx->win, game->rendering_buffer, 0,
			0);
		// mlx_put_image_to_window(mlx->mlx, mlx->win, get_texture(MAP), 0, 0);
		// Calcul du temps écoulé en millisecondes
		time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
		printf("Temps d'exécution : %.3f ms\n", time_taken);
}
