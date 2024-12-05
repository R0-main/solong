/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/10/26 13:05:34 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (
		--n > 0
		&& (unsigned char *)s1
		&& (unsigned char *)s2
		&& *(unsigned char *)s1 == *(unsigned char *)s2
	)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

// #include <string.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	str1[] = "{ '\0',";
// 	char	str2[] = "{ '\0', '\201' }";

// 	printf("- %d\n", memcmp(str1, str2, 1));
// 	printf("- %d\n", ft_memcmp(str1, str2, 1));
// 	return (0);
// }
