/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:02:25 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/07 10:39:01 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_next_percent_index(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	return (i);
}

void	handle_percent(const char *format, va_list args, int i, int *total_len)
{
	if (format[i + 1] == '%')
	{
		ft_putchar_fd('%', 1);
		*total_len += 1;
	}
	else if (format[i + 1] == 'c')
		*total_len += handle_char(args);
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		*total_len += handle_num(args);
	else if (format[i + 1] == 'u')
		*total_len += handle_unsigned_num(args);
	else if (format[i + 1] == 's')
		*total_len += handle_str(args);
	else if (format[i + 1] == 'x')
		*total_len += handle_hex(args);
	else if (format[i + 1] == 'X')
		*total_len += handle_big_hex(args);
	else if (format[i + 1] == 'p')
		*total_len += handle_address(args);
}

size_t	get_len_num(long n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		++i;
	}
	while (n > 0 && ++i)
		n /= 10;
	return (i);
}

// void	handle_len(const char *format, int i, int *total_len)
// {

// 	if (format[i + 1] == '%')
// 		total_len ++;
// 	else if (format[i + 1] == 'c')
// 		total_len ++;
// 	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
// 		total_len += handle_num(ar)
// 	else if (format[i + 1] == 'u')
// 		ft_unsigned_putnbr((unsigned int)va_arg(args, unsigned int));
// 	else if (format[i + 1] == 's')
// 		ft_putstr_fd(va_arg(args, char *), 1);
// 	else if (format[i + 1] == 'x')
// 		ft_print_hex_x(va_arg(args, unsigned int), 0);
// 	else if (format[i + 1] == 'X')
// 		ft_print_hex_big_x(va_arg(args, unsigned int), 0);
// 	else if (format[i + 1] == 'p')
// 		ft_print_hex_x(va_arg(args, unsigned long), 1);
// }

int	get_format_len(const char *format)
{
	int	i;
	int	l;

	i = -1;
	l = 0;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
		}
		else
		{
			l++;
		}
	}
	return (l);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;
	int		total_len;

	i = -1;
	total_len = 0;
	if (format == 0)
		return (-1);
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
			handle_percent(format, args, i++, &total_len);
		else
		{
			len = get_next_percent_index(format + i);
			write(1, format + i, len);
			i += len - 1;
		}
	}
	total_len += get_format_len(format);
	va_end(args);
	return (total_len);
}
