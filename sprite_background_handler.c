/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_background_handler.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:38:34 by yasmail           #+#    #+#             */
/*   Updated: 2026/02/17 18:01:52 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	sprite_background_handler(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->count_sprite_background)
	{
		draw_sprite_on_canvas(&game->canvas, &game->sprite_background[i]);
		i++;
	}
}
