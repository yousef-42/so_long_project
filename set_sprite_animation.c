/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite_animation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:53:01 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/07 18:39:20 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	set_sprite_animation(t_game *game, int index, int force, int no_loop)
{
	t_sprite	*spr;

	spr = &game->sprite[index];
	if (!force && spr->is_same_anim)
	{
		return ;
	}
	spr->frame = 0;
	spr->animation_timer = 0;
	spr->no_loop = no_loop;
	spr->started = 1;
	change_sprite(game, index, spr->animation_img[0]);
}
