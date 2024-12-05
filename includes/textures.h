/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:06:34 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/03 17:06:41 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H

# define TEXTURES_H

# include "../includes/mlx.h"
# include "../includes/mlx_int.h"

# define GRASS_TEXTURE 0
# define PLAYER_TEXTURE 1
# define SARAH_TEXTURE 2

# define MAX_TEXTURES 256

typedef struct s_textures_atlas
{
	t_img			*atlas[MAX_TEXTURES];
}					t_textures_atlas;

t_textures_atlas	*get_textures_atlas(void);
int					load_texture(void *mlx, const char *path, int id);
t_img				*get_texture(int id);
t_img				*get_random_rotate_texture(int id);
void				load_assets(void *mlx);
void				unload_assets(void *mlx);

// load("assets/grass.xpm", textures_atlas, GRASS_TEXTURE)

#endif
