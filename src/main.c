/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:01:04 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/07 14:00:35 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game.h"
#include "mlx.h"
#include "mlx_int.h"
#include "mlx_wrapper.h"
#include "textures.h"
#include "utils.h"
#include <stdio.h>
#include <unistd.h>

// define those from parsing

typedef struct s_free_img_mlx
{
	t_mlx	*mlx;
	t_img	*img;
}			t_free_img_mlx;

int	destroy_close(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx);
	return (0);
}

int	close_win(int keycode, t_mlx *mlx)
{
	if (keycode == 65307 || keycode == -16778664)
	{
		mlx_loop_end(mlx->mlx);
		// free(mlx->mlx);
	}
	else if (keycode == 101)
	{
		// mlx_clear_window(mlx->mlx, mlx->win);
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			get_texture(BLACK_SCREEN_TEXTURE), 0, 0);
	}
	else if (keycode == 103)
	{
		// test_game(get_game_instance());
		// print_map();
		// mlx_put_image_to_window(mlx->mlx, mlx->win,
		// 	get_texture(TILE_TEXTURE), )
		// put_img_to_rendering_buffer(get_game_instance(),
		// 	get_texture(TILE_TEXTURE), WIDTH - 32, HEIGHT - 32);
		// render_next_frame(mlx);
		// // put_transparent_texture_on_window(TILE_TEXTURE, mlx, WIDTH / 2,
		// 	HEIGHT / 2);
		// init_bg(mlx);
	}
	else if (keycode == 114)
	{
		mlx_string_put(mlx->mlx, mlx->win, 15, 15, 0xFFFFFFFF,
			"fqwfwqfqfqfqwfq");
	}
	on_key_pressed(keycode);
	ft_printf("pressed : %d\n", keycode);
	return (0);
}

int	main_loop(t_mlx *mlx)
{
	static int	is_init = 0;
	static int	loop = 1000000;

	if (is_init == 0)
	{
		game_init(mlx);
		is_init = 1;
	}
	else
	{
		render_next_frame(mlx);
	}
	loop++;
	// sleep(0);
	return (0);
}

void	handle_pressed_mouse_event(int key, t_mlx *mlx)
{
	t_game	*game;
	int		x;
	int		y;

	x = 0;
	y = 0;
	game = get_game_instance();
	if (!game)
		return ;
	mlx_mouse_get_pos(game->mlx->mlx, game->mlx->win, &x, &y);
	game->last_mouse_location = (t_vec2){x, y};
}

void	handle_release_mouse_event(int x, int y, t_mlx *mlx)
{
	t_game	*game;

	game = get_game_instance();
	if (!game)
		return ;
	game->last_mouse_location = (t_vec2){0, 0};
}

void	handle_mouse_motion_event(int x, int y, t_mlx *mlx)
{
	t_vec2	vec2;
	t_game			*game;

	game = get_game_instance();
	if (!game)
		return ;
	if (!game->last_mouse_location.x || !game->last_mouse_location.y)
		return ;
	vec2 = (t_vec2){game->last_mouse_location.x - x,
		game->last_mouse_location.y - y};
	if (
		game->camera_offsets.x + vec2.x < get_max_x(game)
		&& game->camera_offsets.x + vec2.x > 0
	)
		game->camera_offsets.x += vec2.x;
	if (
		game->camera_offsets.y + vec2.y < get_max_y(game)
		&& game->camera_offsets.y + vec2.y > 0
		)
		game->camera_offsets.y += vec2.y;
	game->last_mouse_location = (t_vec2){x, y};
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_window;
	t_mlx	mlx_vars;

	if (ac == 1)
	{
		ft_printf("[ERROR] : Please provide a map in .ber\n");
		return (1);
	}
	if (!endswith(av[1], ".ber"))
	{
		ft_printf("[ERROR] : Please provide a valid .ber map !");
		return (1);
	}
	if (parse_map(av[1]))
	{
		free_map();
		ft_printf("[ERROR] : Error in the map file !\n");
		return (1);
	}
	mlx = mlx_init();
	mlx_window = NULL;
	if (mlx != 0)
	{
		mlx_window = mlx_new_window(mlx, WIDTH, HEIGHT, "So Long");
		mlx_vars.mlx = mlx;
		mlx_vars.win = mlx_window;
		load_assets(mlx);
		load_animations(mlx);
		mlx_key_hook(mlx_vars.win, close_win, &mlx_vars);
		mlx_hook(mlx_window, MotionNotify, (1L << 8), handle_mouse_motion_event,
			&mlx_vars);
		mlx_hook(mlx_window, ButtonRelease, (1L << 3),
			handle_release_mouse_event, &mlx_vars);
		mlx_hook(mlx_window, ButtonPress, (1L << 2), handle_pressed_mouse_event,
			&mlx_vars);
		mlx_hook(mlx_window, DestroyNotify, 0, destroy_close, &mlx_vars);
		mlx_loop_hook(mlx_vars.mlx, main_loop, &mlx_vars);
		mlx_loop(mlx);
		unload_assets(mlx);
		unload_animations(mlx);
		mlx_destroy_window(mlx, mlx_window);
		mlx_destroy_image(mlx, get_game_instance()->rendering_buffer);
	}
	free_map();
	mlx_destroy_display(mlx);
	free(mlx);
}
