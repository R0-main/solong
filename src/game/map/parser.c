/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:42:59 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/05 18:33:00 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game.h"
#include "get_next_line.h"
#include <unistd.h>

static int	check_for_duplicate_point(t_map *map)
{
	int	x;
	int	y;
	int	find_exit;
	int	find_player;

	y = -1;
	find_exit = 0;
	find_player = 0;
	while (++y < map->height - 1)
	{
		x = -1;
		while (++x < map->witdh - 1)
		{
			if (find_player == 1 && map->buffer[y][x] == 'P')
				return (1);
			else if (find_exit == 1 && map->buffer[y][x] == 'E')
				return (1);
			else if (map->buffer[y][x] == 'P')
				find_player = 1;
			else if (map->buffer[y][x] == 'E')
				find_exit = 1;
		}
	}
	return (0);
}

static int	check_valid_map(t_map *map)
{
	int	y;

	y = 0;
	if (check_for_duplicate_point(map))
		return (1);
	if (!map->buffer)
		return (1);
	if (map->height <= 0 || map->witdh <= 0)
		return (1);
	while (y < map->height - 1)
	{
		if ((int)ft_strlen(map->buffer[y++]) != map->witdh)
			return (1);
	}
	return (0);
}

static int	update_map(t_map *map, int index, char *line)
{
	size_t	l_len;

	if (!line)
		return (1);
	l_len = ft_strlen(line);
	if (!map->witdh)
		map->witdh = l_len - 1;
	if (line[l_len - 1] == '\n')
	{
		map->buffer[index] = ft_substr(line, 0, ft_strlen(line) - 1);
		free(line);
	}
	else
		map->buffer[index] = line;
	return (0);
}

static int	get_lines_count(int fd)
{
	int		count;
	char	*line;

	count = 0;
	line = malloc(1);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	free(line);
	return (count);
}

void	setup_map_coords(void)
{
	t_map			*map;
	t_coordinates	coords;
	int				x;
	int				y;

	x = -1;
	y = -1;
	map = get_map();
	while (++y < map->height - 1)
	{
		while (++x < map->witdh - 1)
		{
			coords.x = x;
			coords.y = y;
			if (map->buffer[y][x] == 'P')
				map->player_spawnpoint = coords;
			else if (map->buffer[y][x] == 'E')
				map->exit_coords = coords;
		}
	}
}

int	parse_map(char *path)
{
	t_map	*map;
	int		fd;
	int		i;
	int		line_count;

	i = 0;
	map = get_map();
	fd = open(path, O_RDONLY);
	if (fd == 1)
		return (1);
	line_count = get_lines_count(fd);
	map->height = line_count;
	close(fd);
	map->buffer = malloc(sizeof(char *) * (line_count + 1));
	if (!map->buffer)
		return (1);
	map->buffer[line_count] = NULL;
	fd = open(path, O_RDONLY);
	if (fd == 1)
		return (1);
	map = get_map();
	while (i < line_count)
		if (update_map(map, i++, get_next_line(fd)))
			break ;
	close(fd);
	return (setup_map_coords(), check_valid_map(map));
}
