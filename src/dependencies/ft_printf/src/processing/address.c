/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:25:52 by rguigneb          #+#    #+#             */
/*   Updated: 2024/11/27 14:18:54 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_address(va_list args)
{
	unsigned long	h;

	h = va_arg(args, unsigned long);
	if (!h)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_print_hex_x((unsigned long long)h, 1);
	return (get_hex_len(h, 1));
}
