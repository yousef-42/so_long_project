/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:09:54 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/07 18:39:31 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	death_animation(t_game *game)
{
	char	*player_anim;

	player_anim = game->sprite[0].animation_img[game->sprite[0].frame];
	if (ft_strnstr(player_anim, "left", ft_strlen(player_anim)))
	{
		create_animation(game, 0, anim_name("Images/death/left/", 4), 0.2);
		set_sprite_animation(game, 0, 0, 1);
	}
	else if (ft_strnstr(player_anim, "right", ft_strlen(player_anim)))
	{
		create_animation(game, 0, anim_name("Images/death/right/", 4), 0.2);
		set_sprite_animation(game, 0, 0, 1);
	}
	else if (ft_strnstr(player_anim, "up", ft_strlen(player_anim)))
	{
		create_animation(game, 0, anim_name("Images/death/up/", 4), 0.2);
		set_sprite_animation(game, 0, 0, 1);
	}
	else if (ft_strnstr(player_anim, "down", ft_strlen(player_anim)))
	{
		create_animation(game, 0, anim_name("Images/death/down/", 4), 0.2);
		set_sprite_animation(game, 0, 0, 1);
	}
	game->sprite[0].layer = 0;
}

static int	hitbox_detect_enemy(t_sprite *a, t_sprite *b, int less_h,
		int less_w)
{
	return (a->x + less_w < b->x + b->w - less_w && a->x + a->w - less_w > b->x
		+ less_w && a->y + less_h < b->y + b->h - less_h && a->y + a->h
		- less_h > b->y + less_h);
}

void	enemy_touched(t_game *game, double delta)
{
	int	i;

	i = 0;
	if (game->game_over_timer > 3)
		exit_handler(game);
	if (game->game_over)
	{
		game->game_over_timer += delta;
		return ;
	}
	while (i < game->count_sprite)
	{
		if (game->sprite[i].enemy)
		{
			if (hitbox_detect_enemy(&game->sprite[0], &game->sprite[i], 2, 10))
			{
				death_animation(game);
				game->game_over = 1;
			}
		}
		i++;
	}
}
