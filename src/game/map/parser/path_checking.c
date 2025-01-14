/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:46:05 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 16:07:57 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "path_finding.h"

void	check_for_possible_paths(t_map *map)
{
	int		i;
	t_path	*path;

	i = -1;
	path = find_path(map->exit_coords, map->player_spawnpoint);
	if (!path)
		exit_error(MAP_PLAYER_CANNOT_EXIT_ERROR);
	free_path_nodes(path);
	while (++i < MAX_COLLECTIBLES)
	{
		if (!map || !map->collectibles_coords[i].x
			|| !map->collectibles_coords[i].y)
			continue ;
		path = find_path(map->collectibles_coords[i], map->player_spawnpoint);
		if (!path)
			exit_error(MAP_PLAYER_CANNOT_ACCESS_ALL_COLLECTIBLE_ERROR);
		free_path_nodes(path);
	}
}
