/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:35:31 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/27 12:37:31 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define HEIGHT 1920
#define WIDTH 1080

int	main(void)
{
	int y;
	int	x;
	int pixels;

	pixels = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixels++;
			x += 1;
		}
		y += 1;
	}
	printf("pixels : %d\n", pixels);
	return (0);
}
