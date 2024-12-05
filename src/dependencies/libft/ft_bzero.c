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

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = s;
	while (ptr && i++ < n)
		*ptr++ = 0;
}

//#include <stdio.h>
//#include <string.h>

//int	main(void)
//{
//	char	str[] = "Romain";
//
//	printf("%s\n", str);
//	bzero(str, 1);
//	printf("%s\n", str);
//	printf("%c\n", str[1]);
//	
//	char	str2[] = "Romain";
//	printf("%s\n", str2);
//	ft_bzero(str2, 1);
//	printf("%s\n", str2);
//	printf("%c\n", str2[1]);
//	return (0);
//}