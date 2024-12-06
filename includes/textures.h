/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:06:34 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/06 19:26:58 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H

# define TEXTURES_H

# include "game.h"
# include "mlx.h"
# include "mlx_int.h"

# define TILE_X 32
# define TILE_Y 32

typedef enum e_textures
{
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
t_img				*get_texture(int id);
void				put_img_to_rendering_buffer(t_game *game, t_img *img,
						int ox, int oy);
void				load_assets(void *mlx);
void				unload_assets(void *mlx);

void				put_transparent_texture_on_window(int id, t_mlx *mlx,
						int ox, int oy);

// load("assets/grass.xpm", textures_atlas, GRASS_TEXTURE)

#endif
