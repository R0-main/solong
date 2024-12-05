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

void	ft_putstr_fd(char *s, int fd)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	write(fd, s, s_len);
}

// #include <stdio.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	char* fileName = "file2.txt";

//     int fd = open(fileName, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG);
//     if(fd == -1){
//         printf("\nError Opening File!!\n");
//         exit(1);
//     }
//     else{
// 		printf("fd : %d\n", fd);
// 		printf("fd : %d\n", O_RDWR);
// 		printf("fd : %d\n", O_CREAT);
// 		printf("fd : %d\n", S_IRWXU);
// 		printf("fd : %d\n", S_IRWXG);
// 		printf("fd : %d\n", O_RDWR | O_CREAT | S_IRWXU | S_IRWXG);
//         ft_putstr_fd("no way it is writting in a filfwfqfqe !", fd);
//     }
// 	return (0);
// }
