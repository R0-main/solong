/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:30:56 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/24 17:35:02 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "path_finding.h"
#include "rendering.h"

t_game	*get_game_instance(void)
{
	static t_game	game_instance = {};

	return (&game_instance);
}

void	free_entities(t_game *game)
{
	t_entity	*tmp;

	while (game->entities)
	{
		tmp = game->entities;
		game->entities = game->entities->next;
		if (tmp && tmp->path_to_follow)
			free_path_nodes(tmp->path_to_follow);
		free(tmp);
	}
}

void	init_games_entities(t_game *game)
{
	int	i;

	i = 0;
	if (!game || !game->map)
		return ;
	create_player_entity(game);
	create_exit_entity(game);
	while (i < MAX_COLLECTIBLES)
	{
		if (game->map->collectibles_coords[i].x
			&& game->map->collectibles_coords[i].y)
			create_collectible_entity(game->map->collectibles_coords[i]);
		i++;
	}
	i = 0;
	while (i < MAX_ENEMIES)
	{
		if (game->map->enemies_coords[i].x && game->map->enemies_coords[i].y)
			create_enemy_entity(game->map->enemies_coords[i]);
		i++;
	}
}

void	game_init(t_mlx *mlx)
{
	t_game	*game;

	game = get_game_instance();
	game->map = get_map();
	game->rendering_buffer = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!game->rendering_buffer)
		exit_error(GAME_RENDERING_BUFFER_MALLOC_FAILED);
	game->rendering_buffer_data.endian = 0;
	game->rendering_buffer_data.line_bytes = 0;
	game->rendering_buffer_data.pixel_bits = 0;
	mlx_get_data_addr(game->rendering_buffer,
		&game->rendering_buffer_data.pixel_bits,
		&game->rendering_buffer_data.line_bytes,
		&game->rendering_buffer_data.endian);
	game->mlx = mlx;
	game->camera_offsets = (t_vec2){0, 0};
	game->steps_made = 0;
	init_map_img(game);
	game->entities = NULL;
	game->init = true;
	mlx_get_data_addr(game->map->map_img, &game->map->map_img_data.pixel_bits,
		&game->map->map_img_data.line_bytes, &game->map->map_img_data.endian);
	init_games_entities(game);
}

void	render_next_frame(t_mlx *mlx)
{
	t_game			*game;

	game = get_game_instance();
	if (!game || !game->init)
		return ;
	mlx_destroy_image(mlx->mlx, game->rendering_buffer);
	game->rendering_buffer = mlx_new_image(game->mlx->mlx, WIDTH, HEIGHT);
	game->tick++;
	if (!game->rendering_buffer)
		return ;
	on_game_tick(game);
	draw_map(game);
	write_score_on_screen(game);
	entities_loop(game);
	proccess_rendering_buffer(game);
	mlx_put_image_to_window(mlx->mlx, mlx->win, game->rendering_buffer, 0, 0);
}

/*
void	render_next_frame(t_mlx *mlx)
{
	double			time_taken;
	static float	max;
	t_game			*game;
	static int		i = 0;

	clock_t start, end;
	start = clock();
	game = get_game_instance();
	if (!game || !game->init)
		return ;
	mlx_destroy_image(mlx->mlx, game->rendering_buffer);
	game->rendering_buffer = mlx_new_image(game->mlx->mlx, WIDTH, HEIGHT);
	game->tick++;
	if (!game->rendering_buffer)
		return ;
	on_game_tick(game);
	draw_map(game);
	entities_loop(game);
	write_score_on_screen(game);
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
*/
