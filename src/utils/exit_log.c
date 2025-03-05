/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_log.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:47:23 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/15 10:59:42 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game.h"
#include "mlx_wrapper.h"
#include <stdlib.h>
#include "errors.h"

void	put_log(const char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
		i++;
	write(1, "\033[38;2;169;169;169m[\033[0m", 25);
	write(1, "\033[38;2;30;144;255mLog\033[0m", 26);
	write(1, "\033[38;2;169;169;169m]\033[0m", 25);
	write(1, " ", 1);
	write(1, msg, i);
	write(1, "\n", 1);
}

void	exit_log(const char *msg)
{
	t_game	*game;

	game = get_game_instance();
	if (game)
		free_all();
	put_log(msg);
	exit(EXIT_SUCCESS);
}
