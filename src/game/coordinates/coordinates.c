/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:16:24 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/07 09:42:45 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

bool	is_same_position(t_vec2 pos1, t_vec2 pos2)
{
	return (pos1.x == pos2.x && pos1.y == pos2.y);
}

bool	is_between(t_vec2 pos, t_vec2 bpos1, t_vec2 bpos2)
{
	return (pos.x >= bpos1.x && pos.x <= bpos2.x && pos.y >= bpos1.y
		&& pos.y <= bpos2.y);
}
