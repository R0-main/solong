/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_wrapper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:33:15 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/16 08:58:44 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WRAPPER_H

# define MLX_WRAPPER_H

# define HEIGHT 520
# define WIDTH 856

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
}			t_mlx;

typedef struct s_img_data
{
	int		line_bytes;
	int		pixel_bits;
	int		endian;
}			t_img_data;

t_mlx		*get_mlx_vars(void);
void		free_all(void);

#endif
