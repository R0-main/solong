/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:58:00 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 14:44:05 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_H

# define ENTITIES_H

# include "animations.h"
# include "path_finding.h"
# include "textures.h"
# include "utils.h"

struct s_game;
typedef struct s_game	t_game;

# define MAX_ENTITIES 255

typedef enum e_entity_type
{
	PLAYER_TYPE,
	COLLECTIBLE_TYPE,
	EXIT_TYPE,
}						t_entity_type;

typedef struct s_entity
{
	int					hp;
	t_entity_type		type;
	t_vec2				pos;
	t_texture			texture;
	t_texture			directions_textures[4];
	t_animation_frame	*idle_animation;
	t_direction			direction;
	t_direction			last_direction;
	t_path				*path_to_follow;
	struct s_entity		*next;
	struct s_entity		*prev;
}						t_entity;

void					free_entities(t_game *game);

t_entity				*create_entity(t_entity_type type, t_vec2 pos);
void					remove_entity(t_entity *entity);
void					add_to_entities_list(t_entity *entity);

void					create_player_entity(t_game *game);
void					create_collectible_entity(t_game *game, t_vec2 pos);
void					create_exit_entity(t_game *game);

void					entities_loop(t_game *game);
void					handle_player(t_game *game, t_entity *player);

t_entity				*get_entity_at_location(t_game *game, t_vec2 pos,
							t_entity_type type);

void					rotate_entity_texture(t_game *game, t_entity *entity,
							t_direction direction);

#endif
