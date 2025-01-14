/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:05:56 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 13:48:20 by rguigneb         ###   ########.fr       */
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

typedef struct s_vec2
{
	int	x;
	int	y;
}		t_vec2;

int		endswith(char *str, char *substr);
void	free_2d_buffer(void **_2d_buffer, int len);
void	delay(int loop);

int		ft_max(int a, int b);
int		ft_min(int a, int b);

#endif
