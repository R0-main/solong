/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_loader.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:20:01 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/07 11:51:21 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animations.h"

void	load_animations(void *mlx)
{
	t_animation_parameters	params;

	// params.frame_length.x = 44;
	// params.frame_length.x = 25;
	// params.
	load_animation(mlx, "./assets/coin.xpm", COIN_ANIMATION,
		(t_animation_parameters){(t_vec2){/* x : */ 44, /* y : */ 25},
		/*speed :*/ 15,
		/*frame count :*/ 16});
}
