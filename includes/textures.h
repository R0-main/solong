/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:06:34 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 13:48:30 by rguigneb         ###   ########.fr       */
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

struct s_game;
typedef struct s_game	t_game;

typedef struct s_texture
{
	t_img				*img;
	t_img_data			img_data;
}						t_texture;

typedef enum e_textures
{
	MAP,
	GRASS_TEXTURE,
	PLAYER_TEXTURE,
	PLAYER_TEXTURE_TOP,
	PLAYER_TEXTURE_BOTTOM,
	PLAYER_TEXTURE_RIGHT,
	PLAYER_TEXTURE_LEFT,
	SARAH_TEXTURE,
	TILE_TEXTURE,
	TEST_TILE_TEXTURE,
	ROCK_TEXTURE,
	COIN_TEXTURE,
}						t_textures_definition;

# define MAX_TEXTURES 256

typedef struct s_textures_atlas
{
	t_texture			atlas[MAX_TEXTURES];
}						t_textures_atlas;

typedef struct s_pixels_optimisation
{
	int32_t				a;
	int32_t				b;
	int32_t				c;
	int32_t				d;
	int32_t				e;
	int32_t				f;
}						t_pixels_optimisation;

t_textures_atlas		*get_textures_atlas(void);
int						load_texture(void *mlx, const char *path, int id);
t_texture				get_texture(int id);
void					load_assets(void *mlx);
void					add_asset(int id, t_img *img);
void					unload_assets(void *mlx);

void					put_img_to_into_img(t_img *dest_img, t_img *img,
							t_vec2 offset);

int						init_map_img(t_game *game);

void					put_img_to_into_img_with_offset(t_img *dest_img,
							t_vec2 dest_offset, t_img *img, t_vec2 img_offset);
int32_t					*get_pixel(t_img *asset, t_vec2 coords);

// load("assets/grass.xpm", textures_atlas, GRASS_TEXTURE)

#endif
