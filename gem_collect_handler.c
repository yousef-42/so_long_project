/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gem_collect_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:36:27 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/07 18:45:20 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	free_animation(char **anima)
{
	size_t	j;

	j = 0;
	if (!anima)
		return ;
	while (anima[j])
	{
		free(anima[j]);
		j++;
	}
	if (anima)
		free(anima);
}

static int	hitbox_detect_gem(t_sprite *a, t_sprite *b, int less_h, int less_w)
{
	return (a->x + less_w < b->x + b->w - less_w && a->x + a->w - less_w > b->x
		+ less_w && a->y + less_h < b->y + b->h - less_h && a->y + a->h
		- less_h > b->y + less_h);
}

void	gem_collect_handler(t_game *game)
{
	int	co;

	co = 0;
	while (co < game->count_sprite)
	{
		if (hitbox_detect_gem(&game->sprite[0], &game->sprite[co], 5, 10)
			&& game->sprite[co].collectable)
		{
			if (game->sprite[co].animation_img)
				free_animation(game->sprite[co].animation_img);
			mlx_destroy_image(game->mlx, game->sprite[co].img);
			game->sprite[co].img = NULL;
			if (co != game->count_sprite - 1)
				game->sprite[co] = game->sprite[game->count_sprite - 1];
			game->coins_left--;
			game->count_sprite--;
		}
		else
			co++;
	}
}
