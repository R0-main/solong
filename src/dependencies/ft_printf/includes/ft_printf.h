/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:42:59 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/07 10:38:58 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# include "libft.h"
# include "stdarg.h"
# include "stdio.h"

# define FT_PRINTF_H

int		ft_printf(const char *format, ...);
int		ft_unsigned_putnbr(unsigned int n);
void	ft_print_hex_x(unsigned long num_hex, int pre);
void	ft_print_hex_big_x(unsigned long num_hex, int pre);

size_t	get_len_num(long n);
size_t	get_hex_len(unsigned long num, int pre);

int		handle_char(va_list args);
int		handle_str(va_list args);
int		handle_unsigned_num(va_list args);
int		handle_num(va_list args);
int		handle_hex(va_list args);
int		handle_big_hex(va_list args);
int		handle_address(va_list args);

char	*ft_get_hex(unsigned long freeze, unsigned long num, int pre);

#endif
