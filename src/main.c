/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:01:04 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/13 18:51:35 by romain           ###   ########.fr       */
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

int	destroy_close(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx);
	return (0);
}

int	main_loop(t_mlx *mlx)
{
	static int	is_init = 0;

	// static int	loop = 1000000;
	if (is_init == 0)
	{
		game_init(mlx);
		is_init = 1;
	}
	else
	{
		render_next_frame(mlx);
	}
	// loop++;
	return (0);
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_window;
	t_mlx	*mlx_vars;

	if (ac == 1)
		return (ft_printf("[ERROR] : Please provide a map in .ber\n"), 1);
	if (!endswith(av[1], ".ber"))
		return (ft_printf("[ERROR] : Please provide a valid .ber map !"), 1);
	parse_map(av[1]);
	mlx = mlx_init();
	mlx_vars = get_mlx_vars();
	mlx_window = NULL;
	mlx_vars->win = NULL;
	mlx_vars->mlx = mlx;
	if (mlx != 0)
	{
		mlx_window = mlx_new_window(mlx, WIDTH, HEIGHT, "So Long");
		mlx_vars->win = mlx_window;
		load_assets(mlx);
		load_animations(mlx);
		mlx_key_hook(mlx_vars->win, handle_key, mlx_vars);
		mlx_hook(mlx_window, MotionNotify, (1L << 8),
			(int (*)())handle_mouse_motion_event, &mlx_vars);
		mlx_hook(mlx_window, ButtonRelease, (1L << 3),
			(int (*)())handle_release_mouse_event, mlx_vars);
		mlx_hook(mlx_window, ButtonPress, (1L << 2),
			(int (*)())handle_pressed_mouse_event, &mlx_vars);
		mlx_hook(mlx_window, DestroyNotify, 0, destroy_close, mlx_vars);
		mlx_loop_hook(mlx_vars->mlx, main_loop, mlx_vars);
		mlx_loop(mlx);
	}
	free_all();
}
