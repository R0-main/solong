/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2d_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:05:34 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/05 16:54:35 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_2d_buffer(void **_2d_buffer, int len)
{
	int	x;

	x = 0;
	while (x < len - 1 && _2d_buffer[x])
	{
		free(_2d_buffer[x]);
		x++;
	}
	free(_2d_buffer);
}
