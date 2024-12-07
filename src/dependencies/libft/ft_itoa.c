/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/07 10:42:30 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_number_len(long n)
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

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	is_negative;
	size_t	number_len;
	long	nb;
	char	*result;

	nb = (long)n;
	i = get_number_len(nb);
	is_negative = nb < 0;
	number_len = i;
	result = (char *)malloc(number_len * sizeof(char) + 1);
	if (!result)
		return (NULL);
	if (is_negative)
		nb = -nb;
	while (--i < number_len)
	{
		result[i] = nb % 10 + '0';
		nb /= 10;
	}
	if (is_negative)
		result[0] = '-';
	result[number_len] = 0;
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int	main(void)
// {
// 	printf("%s", ft_itoa(-2147483648));
// 	// char	str[] = "a	b b";
// 	// char	**tab = ft_split(str, ' ');
// 	// size_t	i = 0;

// 	// while (tab[i] != NULL)
// 	// 	printf("- %s\n", tab[i++]);
// 	// //printf("%c", dest1[4]);
// 	// return (0);
// }
