/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_wrapper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:33:15 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/05 21:51:04 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WRAPPER_H

# define MLX_WRAPPER_H

# define HEIGHT 850
# define WIDTH 1500

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

// -----------------------------------------
//
//    Main Section
//
// -----------------------------------------

t_mlx		*get_mlx_vars(void);
void		free_all(void);

#endif
