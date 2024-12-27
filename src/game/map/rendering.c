/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:01:51 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/27 17:09:06 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

int	draw_map(t_game *game)
{
	int				y;
	int				x;
	t_coordinates	coords;
	t_rendering_element	*r_element;

	y = 0;
	while (y < game->rendering_buffer->height)
	{
		x = 0;
		while (x < game->rendering_buffer->width)
		{
			coords = get_to_world_coord(x + game->camera_offsets.x, y + game->camera_offsets.y);
			coords.x = ((coords.x + TILE_X / 2) + (game->map->witdh * TILE_X)
					/ 2);
			r_element = create_rendering_element(get_texture(TILE_TEXTURE), coords);
			add_to_rendering_proccess(r_element, game);
			x += TILE_X;
		}
		y += TILE_Y;
	}
	return (0);
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

	t_rendering_element	*test = create_rendering_element(get_texture(PLAYER_TEXTURE), (t_coordinates){124 + game->camera_offsets.x, 124 + game->camera_offsets.y});
	add_to_rendering_proccess(test, game);

	t_rendering_element	*test2 = create_rendering_element(get_texture(PLAYER_TEXTURE), (t_coordinates){130 + game->camera_offsets.x, 130 + game->camera_offsets.y});
	add_to_rendering_proccess(test2, game);
	
	draw_map(game);
	printf("height : %d\n", game->rendering_queue->position.x);
	proccess_rendering_buffer(game);
	mlx_put_image_to_window(mlx->mlx, mlx->win, game->rendering_buffer,  0, 0);
    end = clock();

    // Calcul du temps écoulé en millisecondes
    time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

    printf("Temps d'exécution : %.3f ms\n", time_taken);
}
