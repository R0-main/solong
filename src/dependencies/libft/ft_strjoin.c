/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/10/24 14:42:23 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	size_t	total_len;
	char	*result;

	i = -1;
	k = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = (char *)malloc(sizeof(char) * total_len);
	if (!result)
		return (NULL);
	while (s1[++i])
		result[k++] = s1[i];
	i = -1;
	while (s2[++i])
		result[k++] = s2[i];
	result[k] = 0;
	return (result);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	str[] = "";
// 	char	dest[] = "";

// 	printf("- %s", ft_strjoin(str, dest));
// 	//printf("%c", dest1[4]);
// 	return (0);
// }
