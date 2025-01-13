/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:47:23 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/13 15:15:25 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game.h"
#include "mlx_wrapper.h"
#include <stdlib.h>

void	ft_putstr_error(const char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
		i++;
	write(2, msg, i);
	write(2, "\n", 1);
}

void	exit_error(const char *msg)
{
	t_game	*game;

	game = get_game_instance();
	if (game)
		free_all();
	ft_putstr_error(msg);
	exit(EXIT_FAILURE);
}
