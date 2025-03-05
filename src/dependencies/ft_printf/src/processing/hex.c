/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:25:52 by rguigneb          #+#    #+#             */
/*   Updated: 2024/11/27 14:19:09 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// protect hex malloc

int	handle_hex(va_list args)
{
	unsigned int	h;

	h = va_arg(args, unsigned int);
	if (h == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	ft_print_hex_x((unsigned long long)h, 0);
	return (get_hex_len((unsigned long)h, 0));
}

int	handle_big_hex(va_list args)
{
	unsigned int	h;

	h = va_arg(args, unsigned int);
	if (h == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	ft_print_hex_big_x((unsigned long long)h, 0);
	return (get_hex_len((unsigned long)h, 0));
}
