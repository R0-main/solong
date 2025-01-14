/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:05:56 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 10:37:06 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H

# include <stdio.h>
# include <stdlib.h>

typedef enum e_directions
{
	UP,
	DOWN,
	RIGHT,
	LEFT
}		t_direction;

int		endswith(char *str, char *substr);
void	free_2d_buffer(void **_2d_buffer, int len);
void	delay(int loop);

int		ft_max(int a, int b);
int		ft_min(int a, int b);

#endif
