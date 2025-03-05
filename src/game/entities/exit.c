/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:10:54 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/15 10:12:53 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "path_finding.h"

void	create_exit_entity(t_game *game)
{
	t_entity	*exit;

	exit = create_entity(EXIT_TYPE, game->map->exit_coords);
	exit->hp = 20;
	exit->texture = get_texture(EXIT_CLOSE_TEXTURE);
}
