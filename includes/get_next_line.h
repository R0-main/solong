/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:56:50 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/05 16:11:34 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define FD_MAX 128

typedef struct s_fd_line_state
{
	char	b[BUFFER_SIZE];
	size_t	o;
	int		end;
}			t_fd_line_state;

char		*get_next_line(int fd);

// UTILS
long long	get_next_line_index(char *str);
void		ft_bzero(void *s, size_t n);
char		*ft_strncatdup(char *src, char *second, size_t max);

#endif
