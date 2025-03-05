/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/11/08 13:15:10 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	end;

	first = 0;
	end = ft_strlen(s1) - 1;
	while (is_in_set(s1[first], set))
		first++;
	while (is_in_set(s1[end], set))
		end--;
	return (ft_substr(s1, first, end - first + 1));
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	str[] = "    	Romain 			";
// 	char	set[] = " 	d";

// 	printf("- %s", ft_strtrim(str, set));
// 	//printf("%c", dest1[4]);
// 	return (0);
// }
