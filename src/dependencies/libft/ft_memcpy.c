/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/10/02 15:03:41 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
	{
		*((char *)dest) = *((const char *)src);
		dest++;
		src++;
	}
	return (dest - n);
}

//#include <stdio.h>
//#include <string.h>
//
//int	main(void)
//{
//	char	str[] = "Nuts Channel is Back";
//
//	printf("%s : %p\n", str, str);
//	printf("%p\n", (char *)ft_memcpy(str + 2, str, 5));
//	printf("%s : %p\n", str, str);
//	
//	char	str2[] = "Nuts Channel is Back";
//	printf("%s\n", str2);
//	memcpy(str2 + 2, str2, 5);
//	printf("%s\n", str2);
//}
//
//#include <string.h>
//#include <stdio.h>
//int	main(void)
//{
//	int	str1 = 654;
//	int	str2 = -4000;
//
//	int	str3 = 654;
//	int	str4 = -4001;
//	void *copy = ft_memcpy(&str1, &str2, 4);
//	str2 = -500;
//	printf("Pointeur après memcpy : %d : %p\n", *(int *)copy, copy);
//	*(int *)copy+=1;
//	printf("str 2 : %d : %p\n", str2, &str2);
//	printf("Pointeur avant memcpy : %d : %p
//	\n", *(int *)&str1, &str1);
//	printf("Pointeur avant memcpy : %d : %p
//	\n", *(int *)(&str1 + 4), (&str1 + 4));
//	printf("%d\n", *(int *)ft_memcpy(&str1, &str2, 4));
//	printf("%d", *(int *)memcpy(&str3, &str4, 4));
//	return (0);
//}
