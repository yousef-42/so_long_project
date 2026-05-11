/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:48:22 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/07 18:39:50 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	player_animation(t_game *game, int x_side, int y_side)
{
	if (x_side < 0)
	{
		create_animation(game, 0, anim_name("Images/walk/left/", 2), 0.3);
		set_sprite_animation(game, 0, 0, 0);
	}
	else if (x_side > 0)
	{
		create_animation(game, 0, anim_name("Images/walk/right/", 2), 0.3);
		set_sprite_animation(game, 0, 0, 0);
	}
	if (y_side < 0)
	{
		create_animation(game, 0, anim_name("Images/walk/up/", 2), 0.3);
		set_sprite_animation(game, 0, 0, 0);
	}
	else if (y_side > 0)
	{
		create_animation(game, 0, anim_name("Images/walk/down/", 2), 0.3);
		set_sprite_animation(game, 0, 0, 0);
	}
}
