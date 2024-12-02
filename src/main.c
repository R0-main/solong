/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:01:04 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/02 15:47:36 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_linux/mlx.h"
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	void *mlx;

	mlx = mlx_init();
	if (mlx != 0)
	{
		printf("fqffqfq");
		mlx_new_window(mlx, 1920, 1080, "Hello world!");
		mlx_loop(mlx);
		// the rest code using mlx variable
	}
}