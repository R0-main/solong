/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/10/26 13:05:34 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = -1;
	while (s[++i])
		f(i, s + i);
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// void	transform(unsigned int i, char* c)
// {
// 	*c = *c + i;
// }

// int	main(void)
// {
// 	char	str[] = "abcde";
// 	ft_striteri(str, transform);
// 	printf("- %s", str);
// 	return (0);
// }
