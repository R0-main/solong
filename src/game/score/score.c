/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:17:12 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/14 17:00:24 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "rendering.h"

void	set_numbers_textures(t_texture numbers[10])
{
	numbers[0] = get_texture(FONT_ZERO_TEXTURE);
	numbers[1] = get_texture(FONT_ONE_TEXTURE);
	numbers[2] = get_texture(FONT_TWO_TEXTURE);
	numbers[3] = get_texture(FONT_THREE_TEXTURE);
	numbers[4] = get_texture(FONT_FOUR_TEXTURE);
	numbers[5] = get_texture(FONT_FIVE_TEXTURE);
	numbers[6] = get_texture(FONT_SIX_TEXTURE);
	numbers[7] = get_texture(FONT_SEVEN_TEXTURE);
	numbers[8] = get_texture(FONT_EIGHT_TEXTURE);
	numbers[9] = get_texture(FONT_NINE_TEXTURE);
}

void	write_score_on_screen(t_game *game)
{
	unsigned long	score;
	unsigned long	num_len;
	t_texture		numbers[10];

	set_numbers_textures(numbers);
	score = game->steps_made;
	num_len = 0;
	if (score == 0)
		render_asset(game, numbers[0], (t_vec2){WIDTH
			- numbers[score].img->width, HEIGHT - numbers[score].img->height});
	while (score)
	{
		render_asset(game, numbers[score % 10], (t_vec2){WIDTH - numbers[score
			% 10].img->width - (numbers[score % 10].img->width * num_len),
			HEIGHT - numbers[score % 10].img->height});
		score /= 10;
		num_len++;
	}
}
