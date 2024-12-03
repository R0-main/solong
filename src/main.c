/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:01:04 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/03 08:13:36 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_linux/mlx.h"
#include "../minilibx_linux/mlx_int.h"
#include <stdio.h>
#include <unistd.h>

// void	*add_img(void *mlx, void *mlx_window)
// {
// 	mlx_pixel_put(mlx, mlx_window, 5, 5, 0x00FF0000);
// 	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// }

#define HEIGHT 540
#define WIDTH 780

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

// slow
int	init_window_bg(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			mlx_pixel_put(vars->mlx, vars->win, i, j, 0x00FF0000);
		}
	}
	return (0);
}

int	load_img(t_vars *vars)
{
	t_img	*img;
	int		h;
	int		w;

	img = mlx_xpm_file_to_image(vars->mlx, "./assets/test.xpm", &w, &h);
	if (!img)
	{
		printf("img loading failed\n");
		return (1);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img, w, h);
	return (0);
}

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_loop_end(vars->mlx);
		// free(vars->mlx);
	}
	else if (keycode == 113)
	{
		init_window_bg(vars);
	}
	else if (keycode == 114)
	{
		mlx_string_put(vars->mlx, vars->win, 15, 15, 0xFFFFFFFF, "fqwfwqfqfqfqwfq");
	}
	else if (keycode == 108)
	{
		load_img(vars);
		printf("tried to load img\n");
	}
	printf("pressed : %d\n", keycode);
	return (0);
}

int	main(void)
{
	void *mlx;
	void *mlx_window;
	t_vars vars;

	mlx = mlx_init();
	mlx_window = NULL;
	if (mlx != 0)
	{
		mlx_window = mlx_new_window(mlx, WIDTH, HEIGHT, "PackPackMan");
		vars.mlx = mlx;
		vars.win = mlx_window;

		mlx_key_hook(vars.win, close_win, &vars);
		mlx_loop(mlx);
	}
	mlx_destroy_display(mlx);
	free(mlx);
}