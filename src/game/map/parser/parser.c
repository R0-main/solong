/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:42:59 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/15 11:55:23 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game.h"
#include "get_next_line.h"
#include "path_finding.h"
#include <unistd.h>

static bool	update_map(t_map *map, int index, char *line)
{
	size_t	l_len;

	if (!line)
		return (true);
	l_len = ft_strlen(line);
	if (!map->width)
		map->width = l_len - 1;
	if (line[l_len - 1] == '\n')
	{
		map->buffer[index] = ft_substr(line, 0, l_len - 1);
		free(line);
	}
	else
		map->buffer[index] = line;
	return (false);
}

static int	get_lines_count(char *path)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (exit_error(MAP_CANNOT_OPEN_FILE_ERROR), false);
	line = malloc(1);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	close(fd);
	free(line);
	return (count);
}

void	init_map(t_map *map, char *path)
{
	int	line_count;

	line_count = get_lines_count(path);
	map->buffer = malloc(sizeof(char *) * (line_count + 1));
	if (!map->buffer)
		exit_error(MAP_MALLOC_FAILED_ERROR);
	map->buffer[line_count] = NULL;
	map->height = line_count - 1;
}

void	parse_map(char *path)
{
	t_map	*map;
	int		i;
	int		fd;

	i = 0;
	map = get_map();
	init_map(map, path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_error(MAP_CANNOT_OPEN_FILE_ERROR);
	while (i < map->height)
		if (update_map(map, i++, get_next_line(fd)))
			break ;
	if (map->height == map->width)
		exit_error(MAP_IS_NOT_RECTANGLE_ERROR);
	close(fd);
	check_map_borders(map);
	check_for_duplicate_point(map);
	setup_map_coords(map);
	check_for_possible_paths(map);
}
