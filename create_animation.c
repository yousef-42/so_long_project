/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:13:13 by yasmail           #+#    #+#             */
/*   Updated: 2026/02/25 19:56:02 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	free_anima(char **anima)
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

static int	same_animation(t_sprite spr, char *anim_type)
{
	if (!spr.animation_img || !spr.animation_img[0] || !anim_type)
		return (0);
	return (ft_strncmp(spr.animation_img[0], anim_type, 30) == 0);
}

void	create_animation(t_game *game, int index, char **anima, double speed)
{
	t_sprite	*spr;

	spr = &game->sprite[index];
	if (!anima || !anima[0])
	{
		free_anima(anima);
		return ;
	}
	if (spr->animation_img && same_animation(*spr, anima[0]))
	{
		spr->is_same_anim = 1;
		free_anima(anima);
		return ;
	}
	else
		spr->is_same_anim = 0;
	if (spr->animation_img)
	{
		free_anima(spr->animation_img);
		spr->animation_img = NULL;
	}
	spr->animation_img = anima;
	spr->frame = 0;
	spr->speed = speed;
}
