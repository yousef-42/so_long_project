/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:21:36 by yasmail           #+#    #+#             */
/*   Updated: 2026/02/17 18:06:48 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	key_initialize(t_game *game)
{
	game->input.key_w = 0;
	game->input.key_a = 0;
	game->input.key_s = 0;
	game->input.key_d = 0;
	game->input.key_pressed_w = 0;
	game->input.key_pressed_a = 0;
	game->input.key_pressed_s = 0;
	game->input.key_pressed_d = 0;
}

void	initialize_game(t_game *game, char *gameName)
{
	game->last_update = 0.0;
	game->mlx = mlx_init();
	game->width = game->size * game->length_horizontal;
	game->height = game->size * game->length_vertical;
	game->window = mlx_new_window(game->mlx, game->width,
			game->height, gameName);
	game->movecount = 0;
	game->input.ismoving = 0;
	key_initialize(game);
}
