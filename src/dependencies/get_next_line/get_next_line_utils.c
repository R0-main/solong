/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:56:55 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/05 16:11:53 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long long	get_next_line_index(char *str)
{
	long long	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(char *)s++ = 0;
}

char	*ft_strncatdup(char *src, char *second, size_t max)
{
	char	*result;
	size_t	i;
	size_t	k;

	i = -1;
	k = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(src) + max + 1) + 1);
	if (!result)
		return (NULL);
	while (src[++i])
		result[k++] = src[i];
	i = -1;
	while (second[++i] && i <= max)
		result[k++] = second[i];
	result[k] = 0;
	if (src)
		free(src);
	return (result);
}
