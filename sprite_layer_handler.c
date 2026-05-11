/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_layer_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:21:56 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/03 18:28:53 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	sprite_layer_handler(t_game *game, int max_layer)
{
	int	i;
	int	layer;

	i = 0;
	layer = 0;
	while (layer < max_layer)
	{
		while (i < game->count_sprite)
		{
			if (game->sprite[i].layer == layer && game->sprite[i].img)
				draw_sprite_on_canvas(&game->canvas, &game->sprite[i]);
			i++;
		}
		i = 0;
		layer++;
	}
}
