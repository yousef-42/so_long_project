/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gems_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:43:10 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/07 18:44:25 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	gems_left(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->count_sprite)
	{
		if (game->sprite[i].collectable)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
