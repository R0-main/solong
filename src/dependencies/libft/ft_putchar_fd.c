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

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <stdio.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	char* fileName = "file2.txt";
//     int fd = open(fileName, O_RDWR | O_CREAT);
//     if(fd == -1){
//         printf("\nError Opening File!!\n");
//         exit(1);
//     }
//     else{
// 		printf("fd : %d", fd);
// 		printf("fd : %d", O_RDWR);
// 		printf("fd : %d", O_CREAT);
// 		printf("fd : %d", O_CREAT | O_RDWR);
//         ft_putchar_fd('c', fd);
//     }
// 	return (0);
// }
