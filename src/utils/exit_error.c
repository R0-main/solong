/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:47:23 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/10 12:51:05 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "mlx_wrapper.h"
#include "game.h"

void	exit_error(const char *msg)
{
	t_game	*game;

	game = get_game_instance();
	if (game)
		free_all();
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}
