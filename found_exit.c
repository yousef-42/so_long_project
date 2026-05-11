/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 21:46:42 by yasmail           #+#    #+#             */
/*   Updated: 2026/02/25 19:56:04 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	win_state(t_game *game, double delta)
{
	game->win_timer += delta;
	if (game->win_timer > 3)
	{
		ft_printf("you win 🥳🎉\n");
		exit_handler(game);
	}
}

static int	must_collect(t_game *game)
{
	if (game->coins_left > 0)
	{
		if (!game->exit_met)
		{
			ft_printf("%s\n", "must collect all the coins first");
			game->exit_met = 1;
		}
		return (1);
	}
	return (0);
}

void	found_exit(t_game *game, double delta)
{
	int	co;

	co = 0;
	while (co < game->count_sprite)
	{
		if (game->sprite[co].exit)
		{
			if (game->sprite[co].x == game->sprite[0].x
				&& game->sprite[co].y == game->sprite[0].y)
			{
				if (must_collect(game))
					return ;
				create_animation(game, 0, anim_name("Images/idle/down/", 2),
					0.3);
				set_sprite_animation(game, 0, 0, 0);
				game->cannot_move = 1;
				game->game_win = 1;
			}
			else
				game->exit_met = 0;
		}
		co++;
	}
	if (game->game_win)
		win_state(game, delta);
}
