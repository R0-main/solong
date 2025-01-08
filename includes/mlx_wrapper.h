/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_wrapper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:33:15 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/08 13:16:58 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WRAPPER_H

# define MLX_WRAPPER_H

# define HEIGHT 520
# define WIDTH 856

# define PIXEL_DEF 1 // 1 pixel = 4 pixels now

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

int			handle_key(int keycode, t_mlx *mlx);

void		handle_pressed_mouse_event(int key, t_mlx *mlx);
void		handle_release_mouse_event(int x, int y, t_mlx *mlx);
void		handle_mouse_motion_event(int x, int y, t_mlx *mlx);

# define LEFT_CLICK 1
# define ESC_KEY 53 // Touche Echap
# define ENTER_KEY 36 // Touche Entrée
# define SPACE_KEY 49 // Touche Espace
# define LEFT_ARROW_KEY 65361 // Flèche gauche
# define RIGHT_ARROW_KEY 65363 // Flèche droite
# define UP_ARROW_KEY 65362 // Flèche haut
# define DOWN_ARROW_KEY 65364 // Flèche bas
# define A_KEY 97 // Touche 'A'
# define S_KEY 115 // Touche 'S'
# define D_KEY 100 // Touche 'D'
# define W_KEY 119 // Touche 'W'
# define Q_KEY 12 // Touche 'Q'
# define Z_KEY 6 // Touche 'Z'
# define X_KEY 7 // Touche 'X'
# define C_KEY 8 // Touche 'C'
# define R_KEY 15 // Touche 'R'
# define F_KEY 3 // Touche 'F'
# define G_KEY 5 // Touche 'G'
# define H_KEY 4 // Touche 'H'
# define I_KEY 34 // Touche 'I'
# define J_KEY 38 // Touche 'J'
# define K_KEY 40 // Touche 'K'
# define L_KEY 37 // Touche 'L'
# define M_KEY 46 // Touche 'M'
# define N_KEY 45 // Touche 'N'
# define O_KEY 31 // Touche 'O'
# define P_KEY 35 // Touche 'P'
# define T_KEY 17 // Touche 'T'
# define Y_KEY 16 // Touche 'Y'
# define U_KEY 32 // Touche 'U'
# define V_KEY 9 // Touche 'V'
# define B_KEY 11 // Touche 'B'
# define L_SHIFT_KEY 257 // Maj gauche
# define L_CTRL_KEY 256 // Ctrl gauche
# define L_ALT_KEY 258 // Alt gauche
# define R_SHIFT_KEY 258 // Maj droite
# define R_CTRL_KEY 269 // Ctrl droite
# define R_ALT_KEY 270 // Alt droite

# define KEY_PAD_0 82 // Pavé numérique 0
# define KEY_PAD_1 83 // Pavé numérique 1
# define KEY_PAD_2 84 // Pavé numérique 2
# define KEY_PAD_3 85 // Pavé numérique 3
# define KEY_PAD_4 86 // Pavé numérique 4
# define KEY_PAD_5 87 // Pavé numérique 5
# define KEY_PAD_6 88 // Pavé numérique 6
# define KEY_PAD_7 89 // Pavé numérique 7
# define KEY_PAD_8 91 // Pavé numérique 8
# define KEY_PAD_9 92 // Pavé numérique 9
# define KEY_PAD_ENTER 96 // Entrée du pavé numérique
# define KEY_PAD_PLUS 69 // Plus du pavé numérique
# define KEY_PAD_MINUS 78 // Moins du pavé numérique
# define KEY_PAD_MULTIPLY 67 // Multiplication du pavé numérique
# define KEY_PAD_DIVIDE 75 // Division du pavé numérique

#endif
