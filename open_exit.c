/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 21:37:32 by yasmail           #+#    #+#             */
/*   Updated: 2026/02/25 19:01:53 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	open_exit(t_game *game)
{
	int	co;

	co = 0;
	while (co < game->count_sprite)
	{
		if (game->sprite[co].exit)
		{
			create_animation(game, co,
				ft_split(
					"Images/door/2.xpm,Images/door/3.xpm,Images/door/4.xpm",
					','), 0.2);
			set_sprite_animation(game, co, 0, 1);
			game->sprite[co].wall = 0;
		}
		co++;
	}
}
