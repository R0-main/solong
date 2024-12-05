/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/09/30 20:22:45 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return ((unsigned int) c < 128);
}

//#include <stdio.h>
//
//int	main(void)
//{
//	int	i;
//
//	i = -128;
//	while (i++ < 255)
//		printf("%c : %d\n", i, ft_isascii(i));
//	printf("=====================================");
//	i = -128;
//	while (i++ < 255)
//		printf("%c : %d\n", i, isascii(i));
//
//	printf("%d", (unsigned int)'a');
//	return (0);
//}
