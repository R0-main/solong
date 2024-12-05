/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:16:44 by rguigneb          #+#    #+#             */
/*   Updated: 2024/11/27 14:13:49 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_hex_len(unsigned long num, int pre)
{
	size_t	i;

	i = 0;
	if (num == 0)
		i++;
	while (num > 0)
	{
		num /= 16;
		i++;
	}
	if (pre)
		i += 2;
	return (i);
}

void	ft_print_hex_big_x(unsigned long num_hex, int pre)
{
	static char	hex_base[] = "0123456789ABCDEF";

	if (num_hex <= 0)
		return ;
	if (pre)
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd('x', 1);
	}
	ft_print_hex_big_x(num_hex / 16, 0);
	ft_putchar_fd(hex_base[num_hex % 16], 1);
}

void	ft_print_hex_x(unsigned long num_hex, int pre)
{
	static char	hex_base[] = "0123456789abcdef";

	if (num_hex <= 0)
		return ;
	if (pre)
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd('x', 1);
	}
	ft_print_hex_x(num_hex / 16, 0);
	ft_putchar_fd(hex_base[num_hex % 16], 1);
}
