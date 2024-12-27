/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:16:24 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/27 16:12:01 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

bool	is_same_position(t_coordinates pos1, t_coordinates pos2)
{
	return (pos1.x == pos2.x && pos1.y == pos2.y);
}

bool	is_between(t_coordinates pos, t_coordinates bpos1, t_coordinates bpos2)
{
	return (
		pos.x >= bpos1.x && pos.x <= bpos2.x &&
		pos.y >= bpos1.y && pos.y <= bpos2.y
	);
}
