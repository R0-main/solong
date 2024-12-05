/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/11/06 15:45:31 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (size > 0 && ((size_t)-1) / size < nmemb)
		return (NULL);
	result = (void *)malloc(nmemb * size);
	if (!result)
		return (NULL);
	ft_bzero(result, nmemb * size);
	return (result);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	*tab = (int *)ft_calloc(7, sizeof(int));
// 	if (!tab)
// 		return (1);
// 	size_t	i = 0;
// 	while (i++ < 6)
// 		tab[i] = 1;
// 	i = 0;
// 	while (i++ < 6)
// 		printf("%d\n", tab[i]);
// 	i = 0;
// 	free(tab);
// 	return (0);
// }
