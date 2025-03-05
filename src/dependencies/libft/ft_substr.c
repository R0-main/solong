/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/11/06 15:45:11 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	size_t	s_start_len;
	char	*result;

	i = -1;
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else
	{
		s_start_len = ft_strlen(s + start);
		if (len > s_start_len)
			len = s_start_len;
	}
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	while (s[++i] && i < len)
		result[i] = s[i + start];
	result[i] = 0;
	return (result);
}

// #include <bsd/string.h>
// #include <stdlib.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "Romain";

// 	printf("- %s", ft_substr(str, 1, 4));
// 	return (0);
// }
