/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/10/02 15:02:52 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = dest;
	b = (unsigned char *)src;
	while (n--)
	{
		if (a < b)
			*a++ = *b++;
		else
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	str[] = "Nuts Channel is Back";

// 	printf("%s : %p\n", str, str);
// 	ft_memmove(str + 2, str, 5);
// 	printf("%s : %p\n", str, str);
// 	char	str2[] = "Nuts Channel is Back";
// 	printf("%s\n", str2);
// 	memmove(str2 + 2, str2, 5);
// 	printf("%s\n", str2);
// }
