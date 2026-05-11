/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:13:08 by yasmail           #+#    #+#             */
/*   Updated: 2026/02/10 19:04:53 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	sprite_animation(t_game *game, double delta)
{
	int	i;

	i = 0;
	if (game->initialized_delta == 1)
	{
		while (i < game->count_sprite)
		{
			game->sprite[i].animation_timer += delta;
			if (game->sprite[i].animation_img
				&& game->sprite[i].animation_timer >= game->sprite[i].speed)
			{
				game->sprite[i].animation_timer = 0;
				game->sprite[i].frame++;
				if (!game->sprite[i].animation_img[game->sprite[i].frame])
				{
					game->sprite[i].started = 0;
					game->sprite[i].frame = 0;
				}
				if (game->sprite[i].started || game->sprite[i].no_loop == 0)
					change_sprite(game, i,
						game->sprite[i].animation_img[game->sprite[i].frame]);
			}
			i++;
		}
	}
}
