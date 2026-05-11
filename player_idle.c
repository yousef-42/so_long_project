/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_idle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 20:20:36 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/07 18:40:03 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	any_key_pressed(t_game *game)
{
	return (game->input.key_a || game->input.key_d || game->input.key_w
		|| game->input.key_s);
}

void	player_idle(t_game *game)
{
	char	*player_anim;

	player_anim = game->sprite[0].animation_img[game->sprite[0].frame];
	if (any_key_pressed(game))
		return ;
	if (ft_strnstr(player_anim, "left", ft_strlen(player_anim)))
	{
		create_animation(game, 0, anim_name("Images/idle/left/", 2), 0.3);
		set_sprite_animation(game, 0, 0, 0);
	}
	else if (ft_strnstr(player_anim, "right", ft_strlen(player_anim)))
	{
		create_animation(game, 0, anim_name("Images/idle/right/", 2), 0.3);
		set_sprite_animation(game, 0, 0, 0);
	}
	else if (ft_strnstr(player_anim, "up", ft_strlen(player_anim)))
	{
		create_animation(game, 0, anim_name("Images/idle/up/", 2), 0.3);
		set_sprite_animation(game, 0, 0, 0);
	}
	else if (ft_strnstr(player_anim, "down", ft_strlen(player_anim)))
	{
		create_animation(game, 0, anim_name("Images/idle/down/", 2), 0.3);
		set_sprite_animation(game, 0, 0, 0);
	}
}
