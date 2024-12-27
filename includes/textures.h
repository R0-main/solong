/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:06:34 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/27 15:36:16 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H

# define TEXTURES_H

# include "game.h"
# include "mlx.h"
# include "mlx_int.h"

# define TILE_X 92
# define TILE_Y 81

typedef enum e_textures
{
	MAP,
	BLACK_SCREEN_TEXTURE,
	GRASS_TEXTURE,
	PLAYER_TEXTURE,
	SARAH_TEXTURE,
	TILE_TEXTURE,
	TEST_TILE_TEXTURE
}					t_textures_definition;

# define MAX_TEXTURES 256

typedef struct s_textures_atlas
{
	t_img			*atlas[MAX_TEXTURES];
}					t_textures_atlas;

t_textures_atlas	*get_textures_atlas(void);
int					load_texture(void *mlx, const char *path, int id);
void				load_black_screen_texture(void *mlx);
t_img				*get_texture(int id);
void				put_img_to_rendering_buffer(t_game *game, t_img *img,
						int ox, int oy);
void				load_assets(void *mlx);
void				add_asset(int id, t_img *img);
void				unload_assets(void *mlx);
void				reset_rendering_buffer(t_game *game);

void				put_transparent_texture_on_window(int id, t_mlx *mlx,
						int ox, int oy);

void				put_img_to_into_img(t_img *dest_img, t_img *img, int ox,
						int oy);

int					init_map_img(t_game *game);

int					get_pixel_index(t_img *asset, t_coordinates coords);
int32_t				*get_pixel(t_img *asset, t_coordinates coords);

// load("assets/grass.xpm", textures_atlas, GRASS_TEXTURE)

#endif
