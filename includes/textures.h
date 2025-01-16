/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:06:34 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/16 09:23:39 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H

# define TEXTURES_H

# include "mlx.h"
# include "mlx_int.h"
# include "mlx_wrapper.h"
# include "utils.h"

# define TILE_X 52
# define TILE_Y 46
# define MAX_TEXTURES 256

typedef struct s_texture
{
	t_img			*img;
	t_img_data		img_data;
}					t_texture;

typedef enum e_textures
{
	MAP,
	PLAYER_TEXTURE_TOP,
	PLAYER_TEXTURE_BOTTOM,
	PLAYER_TEXTURE_RIGHT,
	PLAYER_TEXTURE_LEFT,
	TILE_TEXTURE,
	COIN_TEXTURE,
	ENEMY_TEXTURE,
	EXIT_OPEN_TEXTURE,
	EXIT_CLOSE_TEXTURE,
	FONT_ZERO_TEXTURE,
	FONT_ONE_TEXTURE,
	FONT_TWO_TEXTURE,
	FONT_THREE_TEXTURE,
	FONT_FOUR_TEXTURE,
	FONT_FIVE_TEXTURE,
	FONT_SIX_TEXTURE,
	FONT_SEVEN_TEXTURE,
	FONT_EIGHT_TEXTURE,
	FONT_NINE_TEXTURE,
}					t_textures_definition;

typedef struct s_textures_atlas
{
	t_texture		atlas[MAX_TEXTURES];
}					t_textures_atlas;

// -----------------------------------------
//
//    Getter Section
//
// -----------------------------------------

t_texture			get_texture(int id);
t_textures_atlas	*get_textures_atlas(void);

// -----------------------------------------
//
//   Loader / Unloader Section
//
// -----------------------------------------

int					load_texture(void *mlx, const char *path, int id);
void				load_assets(void *mlx);
void				unload_assets(void *mlx);
void				add_asset(int id, t_img *img);

// -----------------------------------------
//
//    Utils Section
//
// -----------------------------------------

void				put_img_to_into_img(t_img *dest_img, t_img *img,
						t_vec2 offset);
void				put_img_to_into_img_with_offset(t_img *dest_img,
						t_vec2 dest_offset, t_img *img, t_vec2 img_offset);
int32_t				*get_pixel(t_img *asset, t_vec2 coords);

#endif
