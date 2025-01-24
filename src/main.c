/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:01:04 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/24 17:35:07 by rguigneb         ###   ########.fr       */
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

	if (is_init == 0)
	{
		game_init(mlx);
		is_init = 1;
	}
	else
		render_next_frame(mlx);
	return (0);
}

void	init_mlx_hooks(t_mlx *mlx)
{
	mlx_key_hook(mlx->win, handle_key, mlx);
	mlx_hook(mlx->win, MotionNotify, (1L << 8),
		(int (*)())handle_mouse_motion_event, &mlx);
	mlx_hook(mlx->win, ButtonRelease, (1L << 3),
		(int (*)())handle_release_mouse_event, mlx);
	mlx_hook(mlx->win, ButtonPress, (1L << 2),
		(int (*)())handle_pressed_mouse_event, &mlx);
	mlx_hook(mlx->win, DestroyNotify, 0, destroy_close, mlx);
	mlx_loop_hook(mlx->mlx, main_loop, mlx);
}

void	load_ressources(t_mlx *mlx)
{
	load_assets(mlx->mlx);
	load_animations(mlx->mlx);
}

int	main(int ac, char **av)
{
	void	*mlx;
	t_mlx	*mlx_vars;

	if (ac > 2)
		exit_error(MAIN_TOO_MANY_ARGS);
	if (ac == 1)
		exit_error(MAIN_NO_ARG);
	if (!endswith(av[1], ".ber"))
		exit_error(MAP_FILE_EXTENSION_ERROR);
	parse_map(av[1]);
	mlx = mlx_init();
	mlx_vars = get_mlx_vars();
	mlx_vars->win = NULL;
	mlx_vars->mlx = mlx;
	if (!mlx)
		exit_error(MLX_ERROR);
	mlx_vars->win = mlx_new_window(mlx, WIDTH, HEIGHT, "So Long");
	if (!mlx_vars->win)
		exit_error(MLX_WINDOW_ERROR);
	load_ressources(mlx_vars);
	init_mlx_hooks(mlx_vars);
	mlx_loop(mlx);
	exit_log(GAME_LEAVE_LOG);
}
