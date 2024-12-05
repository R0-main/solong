/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:01:51 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/05 17:50:59 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	render_map(t_mlx *mlx)
{
	int	x;
	int	y;
	t_map	*map;

	x = 0;
	y = 0;
	map = get_map();
	while (y < map->height - 1)
	{
		while (x < map->witdh - 1)
		{

		}
	}
}
