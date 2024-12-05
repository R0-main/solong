/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/10/15 19:04:14 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

//#include <ctype.h>
//#include <stdio.h>
//int	main(int argc, char **argv)
//{
//	if (argc == 1)
//	{
//		int	i;
//		i = 0;
//
//		while (i++ < 127)
//			printf("%c | %c\n", ft_tolower(i), tolower(i));
//	}
//	else
//	{
//		printf("ft_toupper : %c\n", ft_tolower(argv[1][0]));
//		printf("toupper : %c\n", tolower(argv[1][0]));
//	}
//	return (0);
//}
