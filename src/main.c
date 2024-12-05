/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:01:04 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/05 13:37:30 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_int.h"
#include "textures.h"
#include <stdio.h>
#include <unistd.h>
#include "mlx_wrapper.h"
#include "game.h"
#include "ft_printf.h"

// define those from parsing

typedef struct s_free_img_mlx
{
	t_mlx	*mlx;
	t_img	*img;
}			t_free_img_mlx;

// slow
int	init_window_bg(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, i, j, 0x00FF0000);
		}
	}
	return (0);
}

int	load_img(t_mlx *mlx)
{
	t_img	*img;
	int		h;
	int		w;

	img = mlx_xpm_file_to_image(mlx->mlx, "./assets/test.xpm", &w, &h);
	if (!img)
	{
		printf("img loading failed\n");
		return (1);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, w, h);
	return (0);
}

int	reset_bg(unsigned int color, t_mlx *mlx)
{
	t_img	*img;

	img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	(void)color;
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, 0, 0);
	mlx_pixel_put(mlx->mlx, mlx->win, 5, 5, 0xFFFFFFFF);
	return (0);
}

int	free_img(t_free_img_mlx *free_img_vars)
{
	mlx_destroy_image(free_img_vars->mlx->mlx, free_img_vars->img);
	// free(free_img_vars->img);
	return (0);
}

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
	else if (keycode == 113)
	{
		init_window_bg(mlx);
	}
	else if (keycode == 101)
	{
		mlx_clear_window(mlx->mlx, mlx->win);
	}
	else if (keycode == 103)
	{
		// init_bg(mlx);
	}
	else if (keycode == 114)
	{
		mlx_string_put(mlx->mlx, mlx->win, 15, 15, 0xFFFFFFFF,
			"fqwfwqfqfqfqwfq");
	}
	else if (keycode == 108)
	{
		load_img(mlx);
		printf("tried to load img\n");
	}
	printf("pressed : %d\n", keycode);
	return (0);
}

int	main_loop(t_mlx *mlx)
{
	static int is_init = 0;

	if (is_init == 0)
	{
		game_init(mlx);
		is_init = 1;
	}
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
	if (parse_map(av[1]))
	{
		// error
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
	}
	free_map();
	mlx_destroy_display(mlx);
	free(mlx);
}
