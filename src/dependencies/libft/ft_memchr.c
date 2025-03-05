/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/10/02 15:34:15 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n-- > 0 && s)
		if (*(unsigned char *)s++ == (unsigned char)c)
			return ((void *)s - 1);
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = { '\201' };

// 	printf("%s\n", str);
// 	printf("%s : %s\n", str, (char *)memchr(str, '\201', 15));
// 	char	str2[] = { '\201' };
// 	printf("%s\n", str2);
// 	printf("%s : %s\n", str2, (char *)ft_memchr(str2, '\201', 15));
// 	return (0);
// }
