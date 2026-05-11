/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:19:17 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/07 18:40:45 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	form(t_game *game, char form)
{
	int	x;
	int	y;

	x = (game->width / 2) - ((7 * 8) / 2);
	y = (game->height / 2) - (16 / 2);
	mlx_string_put(game->mlx, game->window, x, y, 0xFFFFFF, "you win");
	if (form == 'x')
		return (x);
	else if (form == 'y')
		return (y);
	else
		return (0);
}

void	text_handler(t_game *game)
{
	char	*move_counter;
	char	*move_number;
	char	*coins_counter;
	char	*coins_left;

	move_number = ft_itoa(game->movecount);
	move_counter = ft_strjoin("Movements:", move_number);
	coins_left = ft_itoa(game->coins_left);
	coins_counter = ft_strjoin("Coins left:", coins_left);
	mlx_string_put(game->mlx, game->window, 10, 25, 0xFFFFFF, move_counter);
	mlx_string_put(game->mlx, game->window, 10, 10, 0xFFFFFF, coins_counter);
	if (game->win_timer > 0.6)
		mlx_string_put(game->mlx, game->window, form(game, 'x'), form(game,
				'y'), 0xFFFFFF, "you win");
	if (game->game_over_timer > 0.6)
		mlx_string_put(game->mlx, game->window, game->width / 2, game->height
			/ 2, 0xFFFFFF, "game over");
	free(move_counter);
	free(move_number);
	free(coins_counter);
	free(coins_left);
}
