/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:23:38 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/07 18:41:34 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	set_sprite_size(t_game *game, char *map)
{
	int	js;
	int	count_sprite;

	count_sprite = 0;
	js = 0;
	while (map[js])
	{
		if (map[js] == '1' || map[js] == 'P' || map[js] == 'C' || map[js] == 'E'
			|| map[js] == '3' || map[js] == '4')
			count_sprite++;
		js++;
	}
	game->count_sprite = count_sprite;
	game->count_sprite_background = (game->length_horizontal
			* game->length_vertical);
	game->sprite = malloc(sizeof(t_sprite) * count_sprite);
	if (!game->sprite)
		exit_handler(game);
	ft_bzero(game->sprite, sizeof(t_sprite) * count_sprite);
	game->sprite_background = malloc(sizeof(t_sprite) * (game->length_horizontal
				* game->length_vertical));
	if (!game->sprite_background)
		exit_handler(game);
}
