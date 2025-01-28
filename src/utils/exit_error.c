/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:47:23 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/28 10:27:08 by rguigneb         ###   ########.fr       */
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
	write(2, "\033[38;2;169;169;169m[\033[0m", 25);
	write(2, "\033[38;2;255;0;0mError\033[0m", 25);
	write(2, "\033[38;2;169;169;169m]\033[0m", 25);
	write(2, " ", 1);
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
