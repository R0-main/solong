/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:16:24 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/09 10:29:40 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

bool	is_same_position(t_vec2 pos1, t_vec2 pos2)
{
	return (pos1.x == pos2.x && pos1.y == pos2.y);
}

bool	is_between_one(int pos, int bpos1, int bpos2)
{
	return (pos >= bpos1 && pos <= bpos2);
}

bool	is_between(t_vec2 pos, t_vec2 bpos1, t_vec2 bpos2)
{
	return (pos.x >= bpos1.x && pos.x <= bpos2.x && pos.y >= bpos1.y
		&& pos.y <= bpos2.y);
}

bool	is_between_zero_and(t_vec2 pos, t_vec2 to)
{
	return (pos.x <= to.x && pos.x >= POSITION_ZERO.x && pos.y <= to.y
		&& pos.y >= POSITION_ZERO.y);
}
