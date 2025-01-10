/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:42:59 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/10 16:08:05 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game.h"
#include "get_next_line.h"
#include "path_finding.h"
#include <unistd.h>

typedef struct s_map_needed_objects
{
	int		exit_count;
	int		player_count;
	int		collectible_count;
}			t_map_needed_objects;

static void	check_for_duplicate_point(t_map *map)
{
	int						x;
	int						y;
	t_map_needed_objects	objects;

	objects = (t_map_needed_objects){0, 0, 0};
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->buffer[y][x] == PLAYER)
				objects.player_count += 1;
			else if (map->buffer[y][x] == EXIT)
				objects.exit_count += 1;
			else if (map->buffer[y][x] == COLLECTIBLE)
				objects.collectible_count += 1;
		}
	}
	if (objects.player_count == 0 || objects.player_count > 1)
		exit_error("map has more than 1 player spawn point or doesn't have any!");
	if (objects.exit_count == 0 || objects.exit_count > 1)
		exit_error("map has more than 1 exit or doesn't have any!");
	if (objects.collectible_count == 0)
		exit_error("map doesn't have any collectible!");
}

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
			&& line[i] != COLLECTIBLE && line[i] != FLOOR)
			return (false);
		i++;
	}
	return (true);
}

static void	check_valid_map(t_map *map)
{
	int	y;

	y = -1;
	check_for_duplicate_point(map);
	if (!map->buffer)
		exit_error("no map buffer provided at check_valid_map!");
	if (map->height <= 0 || map->width <= 0)
		exit_error("map height or/and width are negative in check_valid_map!");
	while (++y < map->height)
	{
		if ((int)ft_strlen(map->buffer[y]) != map->width)
			exit_error("map width is not the same everywhere!");
		else if (map->buffer[y][0] != '1'
			|| map->buffer[y][ft_strlen(map->buffer[y])])
			exit_error("map doesn't have left or/and right border(s)!");
		else if ((y == 0 || y == map->height) && !is_only_wall(map->buffer[y]))
			exit_error("map doesn't have upper or/and bottom border(s)!");
		else if (!is_only_map_element(map->buffer[y]))
			exit_error("map doesn't have only allowed chars!");
	}
}

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
		return (exit_error("cannot open map file!"), false);
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

void	setup_map_coords(t_map *map)
{
	t_vec2	coords;

	coords.y = -1;
	while (++coords.y < map->height)
	{
		coords.x = -1;
		while (++coords.x < map->width)
		{
			if (map->buffer[coords.y][coords.x] == PLAYER)
				map->player_spawnpoint = coords;
			else if (map->buffer[coords.y][coords.x] == EXIT)
				map->exit_coords = coords;
		}
	}
}

void	init_map(t_map *map, char *path)
{
	int	line_count;

	line_count = get_lines_count(path);
	map->buffer = malloc(sizeof(char *) * (line_count + 1));
	if (!map->buffer)
		exit_error("map malloc failed!");
	map->buffer[line_count] = NULL;
	map->height = line_count - 1;
}

void	check_for_possible_paths(t_map *map)
{
	t_path	*path;

	printf("EXIT : %d %d\n", map->exit_coords.x, map->exit_coords.y);
	printf("PLAYER : %d %d\n", map->player_spawnpoint.x, map->player_spawnpoint.y);
	path = find_path(map->exit_coords, map->player_spawnpoint);
	if (!path)
		exit_error("player cannot exit the map!");
	print_path(path);
	free_path_nodes(path);
}

void	parse_map(char *path)
{
	t_map *map;
	int i;
	int fd;

	i = 0;
	map = get_map();
	init_map(map, path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_error("cannot open map file!");
	while (i < map->height)
		if (update_map(map, i++, get_next_line(fd)))
			break ;
	if (map->height == map->width)
		exit_error("map is not a rectangle!");
	close(fd);
	check_valid_map(map);
	setup_map_coords(map);
	check_for_possible_paths(map);

} // CHECK FOR PATHS
