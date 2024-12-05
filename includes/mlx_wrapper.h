/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_wrapper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:33:15 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/05 12:57:53 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WRAPPER_H

# define MLX_WRAPPER_H

# define HEIGHT 920
# define WIDTH 1280

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
}			t_mlx;

#endif
