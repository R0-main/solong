/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:43:30 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/05 13:34:15 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "utils.h"

int	free_map()
{
	t_map	*map;

	map = get_map();
	if (!map->buffer)
		return (0);
	free_2d_buffer((void **)map->buffer, map->height);
	return (0);
}

t_map	*get_map(void)
{
	static t_map	map = {};

	return (&map);
}