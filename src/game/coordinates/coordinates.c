/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:16:24 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 14:15:27 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

bool	is_same_position(t_vec2 pos1, t_vec2 pos2)
{
	return (pos1.x == pos2.x && pos1.y == pos2.y);
}

bool	fast_is_between(t_vec2 pos, t_vec2 bpos1, t_vec2 bpos2)
{
	return (pos.x >= bpos1.x && pos.x <= bpos2.x && pos.y >= bpos1.y
		&& pos.y <= bpos2.y);
}

bool	is_between(t_vec2 pos, t_vec2 bpos1, t_vec2 bpos2)
{
	int	min_x;
	int	max_x;
	int	min_y;
	int	max_y;

	min_x = ft_min(bpos1.x, bpos2.x);
	max_x = ft_max(bpos1.x, bpos2.x);
	min_y = ft_min(bpos1.y, bpos2.y);
	max_y = ft_max(bpos1.y, bpos2.y);
	return (pos.x >= min_x && pos.x <= max_x && pos.y >= min_y
		&& pos.y <= max_y);
}

bool	is_between_zero_and(t_vec2 pos, t_vec2 to)
{
	return (pos.x <= to.x && pos.x >= (t_vec2){0, 0}.x && pos.y <= to.y
		&& pos.y >= (t_vec2){0, 0}.y);
}

unsigned long	distance_between(t_vec2 pos1, t_vec2 pos2)
{
	return (sqrt((pos2.x - pos1.x) + (pos2.y - pos1.y)));
}
