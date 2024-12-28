/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:35:31 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/28 10:37:10 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define HEIGHT 1920
#define WIDTH 1080

int	main(void)
{
	double	time_taken;
	int		y;
	int		x;
	int		pixels;
	char	*test;
	
	test = malloc(1000000000);
	clock_t start, end;
	start = clock();
	pixels = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			test[pixels] = 1;
			pixels++;
			x += 1;
		}
		y += 1;
	}
	printf("pixels : %d\n", pixels);
	end = clock();
	// Calcul du temps écoulé en millisecondes
	time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
	printf("Temps d'exécution : %.3f ms\n", time_taken);
	return (0);
}
