/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/11/08 16:46:02 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (s && i++ < n)
		*(char *)s++ = c;
	return (s - n);
}

//#include <stdio.h>
//
//int	main(void)
//{
//	char	str[] = "Romain";
//
//	printf("%s\n", str);
//	printf("%s : %s\n", str, (char *)memset(str, 'a', 1));
//
//	char	str2[] = "Romain";
//	printf("%s\n", str2);
//	printf("%s : %s\n", str2, (char *)ft_memset(str2, 'a', 1));
//	return (0);
//}
