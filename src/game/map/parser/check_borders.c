/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:48:46 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/28 10:40:37 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

static bool	is_only_wall(char *line)
{
	int	i;

	if (!line)
		return (false);
	i = 0;
	while (line[i])
		if (line[i++] != WALL)
			return (false);
	return (true);
}

static bool	is_only_map_element(char *line)
{
	int	i;

	if (!line)
		return (false);
	i = 0;
	while (line[i])
	{
		if (line[i] != PLAYER && line[i] != WALL && line[i] != EXIT
			&& line[i] != COLLECTIBLE && line[i] != FLOOR && line[i] != ENEMY)
			return (false);
		i++;
	}
	return (true);
}

void	check_map_borders(t_map *map)
{
	int	y;

	y = -1;
	if (!map->buffer)
		exit_error(MAP_BUFFER_ERROR);
	if (map->height <= 0 || map->width <= 0)
		exit_error(MAP_WIDTH_OR_AND_HEIGHT_ERROR);
	while (++y < map->height)
	{
		if ((int)ft_strlen(map->buffer[y]) != map->width)
			exit_error(MAP_WIDTH_ERROR);
		else if (map->buffer[y][0] != '1'
			|| map->buffer[y][ft_strlen(map->buffer[y]) - 1] != '1')
			exit_error(MAP_LEFT_OR_AND_RIGHT_BORDER_ERROR);
		else if ((y == 0 || y == map->height - 1)
			&& !is_only_wall(map->buffer[y]))
			exit_error(MAP_UPPER_OR_AND_BOTTOM_BORDER_ERROR);
		else if (!is_only_map_element(map->buffer[y]))
			exit_error(MAP_NOT_ALLOWED_CHARS_ERROR);
	}
}
