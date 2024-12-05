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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len == size)
		return (dst_len + src_len);
	while (dst_len + i + 1 < size && src[i] && size > dst_len)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (i < size)
		dst[dst_len + i] = '\0';
	if (size <= dst_len)
		return (size + src_len);
	else
		return (dst_len + src_len);
}

// #include <bsd/string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	str[15] = "Romain";
// 	char	dest[110] = "1234567890";

// 	printf("%s %ld\n", dest, strlcat(dest, str, 15));
// 	printf("%s \n", dest);
// 	//printf("%c", dest[4]);

// 	char	str1[15] = "Romain";
// 	char	dest1[110] = "1234567890";

// 	printf("%s %ld\n", dest1, ft_strlcat(dest1, str1, 15));
// 	printf("%s \n", dest1);
// 	//printf("%c", dest1[4]);
// 	return (0);
// }
