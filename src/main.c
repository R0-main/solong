/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:01:04 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/27 14:19:59 by rguigneb         ###   ########.fr       */
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
	else if (loop >= 350)
	{
		loop = 0;
	}
	render_next_frame(mlx);
	loop++;
	// sleep(0);
	return (0);
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
		mlx_key_hook(mlx_vars.win, close_win, &mlx_vars);
		mlx_hook(mlx_window, DestroyNotify, 0, destroy_close, &mlx_vars);
		mlx_loop_hook(mlx_vars.mlx, main_loop, &mlx_vars);
		mlx_loop(mlx);
		unload_assets(mlx);
		mlx_destroy_window(mlx, mlx_window);
		mlx_destroy_image(mlx, get_game_instance()->rendering_buffer);
	}
	free_map();
	mlx_destroy_display(mlx);
	free(mlx);
}
