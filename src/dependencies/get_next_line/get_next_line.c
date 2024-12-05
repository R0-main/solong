/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:56:52 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/05 16:11:19 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_str(char *str, char *buffer, size_t size)
{
	char	*empty;

	if (!str)
	{
		empty = (char *)malloc(1);
		if (!empty)
			return (NULL);
		empty[0] = 0;
		return (ft_strncatdup(empty, buffer, size));
	}
	else
		return (ft_strncatdup(str, buffer, size));
}

void	reset_fd(t_fd_line_state *fd_ste)
{
	if (fd_ste->end == 1)
	{
		fd_ste->end = 0;
		ft_bzero(fd_ste->b, BUFFER_SIZE);
		fd_ste->o = 0;
	}
}

char	*handle_buffering(t_fd_line_state *fd_ste, char *line, long long nl)
{
	char	*new_line;

	new_line = update_str(line, fd_ste->b + fd_ste->o, nl);
	fd_ste->o += nl + 1;
	return (ft_strncatdup(new_line, "", 0));
}

void	handle_reading(t_fd_line_state *fd_ste, char **line, int *read_bytes,
		int fd)
{
	if (ft_strlen(fd_ste->b + fd_ste->o))
		*line = update_str(*line, fd_ste->b + fd_ste->o, BUFFER_SIZE);
	fd_ste->o = 0;
	ft_bzero(fd_ste->b, BUFFER_SIZE);
	*read_bytes = read(fd, fd_ste->b, BUFFER_SIZE);
}

char	*get_next_line(int fd)
{
	static t_fd_line_state	fd_ste[FD_MAX] = {};
	char					*line;
	int						read_bytes;
	long long				nl;

	line = NULL;
	read_bytes = 1;
	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	reset_fd(&fd_ste[fd]);
	while (read_bytes != EOF && read_bytes > 0 && fd_ste[fd].end != 1)
	{
		nl = get_next_line_index(fd_ste[fd].b + fd_ste[fd].o);
		if (nl == -1)
		{
			handle_reading(&fd_ste[fd], &line, &read_bytes, fd);
			if (read_bytes == EOF)
				return (fd_ste[fd].end = 1, free(line), NULL);
		}
		else
			return (handle_buffering(&fd_ste[fd], line, nl));
	}
	if (read_bytes == EOF || read_bytes == 0)
		fd_ste[fd].end = 1;
	return (line);
}

// int main(void)
// {
// 	get_next_line(1);
// 	return (0);
// }

// int	main(void)
// {
// 	char	*name;
// 	int		fd;
// 	char	*temp;

// 	// char	*line;
// 	// printf("Start \n");
// 	// printf("=========================\n");
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	// free(line);
// 	// printf("=========================\n");
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	// free(line);
// 	name = "read_error.txt";
// 	fd = open(name, O_RDONLY);
// 	/* 1 */
// 	printf("%s", get_next_line(fd));
// 	/* 2 */ printf("%s", get_next_line(fd));
// 	// set the next read call to return -1
// 	/* 3 */ printf("%s", get_next_line(fd));
// 	close(fd);
// 	fd = open(name, O_RDONLY);
// 	/* 4 */ printf("%s", get_next_line(fd));
// 	/* 5 */ printf("%s", get_next_line(fd));
// 	/* 6 */ printf("%s", get_next_line(fd));
// 	/* 7 */ printf("%s", get_next_line(fd));
// 	/* 8 */ printf("%s", get_next_line(fd));
// 	return (0);
// }
// line = get_next_line(fd);
// printf("%s", line);
// free(line);
// printf("=========================\n");
