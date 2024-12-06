/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:05:56 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/06 17:06:59 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H

# include <stdio.h>
# include <stdlib.h>

int		endswith(char *str, char *substr);
void	free_2d_buffer(void **_2d_buffer, int len);
void	delay(int loop);

#endif
