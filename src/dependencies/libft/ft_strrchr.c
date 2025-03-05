/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/11/07 16:39:57 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) - 1;
	if (i == (size_t)-1)
		i = 0;
	while (s[i] && s[i] != (unsigned char)c && (unsigned char)c != 0)
		i--;
	if (s[i] == (unsigned char)c || ((unsigned char)c == 0 && s[0] != 0))
		return ((char *)s + i + ((unsigned char)c == 0 && s[0] != 0));
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	str[] = "";

// 	printf("- %p\n", strrchr(str, 0));
// 	printf("- %p\n", ft_strrchr(str, 0));
// 	return (0);
// }
