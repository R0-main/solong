/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:30:56 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/10 11:25:02 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "path_finding.h"

t_game	*get_game_instance(void)
{
	static t_game	game_instance = {};

	return (&game_instance);
}

int	game_init(t_mlx *mlx)
{
	t_game	*game;

	game = get_game_instance();
	game->map = get_map();
	print_map();
	game->rendering_buffer = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!game->rendering_buffer)
		return (1);
	game->rendering_buffer_data.endian = 0;
	game->rendering_buffer_data.line_bytes = 0;
	game->rendering_buffer_data.pixel_bits = 0;
	mlx_get_data_addr(game->rendering_buffer,
		&game->rendering_buffer_data.pixel_bits,
		&game->rendering_buffer_data.line_bytes,
		&game->rendering_buffer_data.endian);
	game->mlx = mlx;
	game->camera_offsets.x = 0;
	game->camera_offsets.y = 0;
	init_map_img(game);
	mlx_get_data_addr(game->map->map_img, &game->map->map_img_data.pixel_bits,
		&game->map->map_img_data.line_bytes, &game->map->map_img_data.endian);
	free_path_nodes(find_path((t_vec2){3, 3}, (t_vec2){5, 5}));
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
