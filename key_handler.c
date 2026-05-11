/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:40:46 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/07 18:43:02 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	key_down(int *input, int *input_pressed)
{
	*input = 1;
	*input_pressed = 1;
}

int	handle_key(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_ESC)
		exit_handler(game);
	else if ((keycode == KEY_W || keycode == KEY_UP)
		&& !game->input.key_pressed_w)
		key_down(&game->input.key_w, &game->input.key_pressed_w);
	else if ((keycode == KEY_A || keycode == KEY_LEFT)
		&& !game->input.key_pressed_a)
		key_down(&game->input.key_a, &game->input.key_pressed_a);
	else if ((keycode == KEY_S || keycode == KEY_DOWN)
		&& !game->input.key_pressed_s)
		key_down(&game->input.key_s, &game->input.key_pressed_s);
	else if ((keycode == KEY_D || keycode == KEY_RIGHT)
		&& !game->input.key_pressed_d)
		key_down(&game->input.key_d, &game->input.key_pressed_d);
	return (0);
}
