/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:43:30 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 16:39:58 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "utils.h"
#include "ft_printf.h"

int	free_map(void)
{
	t_map	*map;

	map = get_map();
	if (!map->buffer)
		return (0);
	free_2d_buffer((void **)map->buffer, map->height + 1);
	return (0);
}

t_map	*get_map(void)
{
	static t_map	map = {};

	return (&map);
}

bool	is_wall(t_map *map, t_vec2 pos)
{
	t_vec2	map_max;

	map_max = (t_vec2){map->width, map->height};
	return (is_between_zero_and(pos, map_max)
		&& map->buffer[pos.y][pos.x] == WALL);
}

bool	is_enemy(t_map *map, t_vec2 pos)
{
	t_vec2	map_max;

	map_max = (t_vec2){map->width, map->height};
	return (is_between_zero_and(pos, map_max)
		&& map->buffer[pos.y][pos.x] == ENEMY);
}

void	print_map(void)
{
	int		i;
	t_map	*map;

	i = 0;
	map = get_map();
	while (i < map->height)
		ft_printf("%s\n", map->buffer[i++]);
}
