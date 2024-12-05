/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:42:59 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/05 13:30:48 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "ft_printf.h"

static int	check_valid_map(t_map *map)
{
	if (!map->buffer)
		return (1);
	if (map->height <= 0 || map->witdh <= 0)
		return (1);
	return (0);
}

int	parse_map(char *path)
{
	t_map	*map;

	ft_printf("%s", path);
	map = get_map();
	return (check_valid_map(map));
}
