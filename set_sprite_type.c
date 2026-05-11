/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:55:36 by yasmail           #+#    #+#             */
/*   Updated: 2026/02/25 18:13:42 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	set_type(t_sprite_info *info, int wall, int coin, int exit)
{
	info->wall = wall;
	info->collectable = coin;
	info->exit = exit;
	info->enemy = 0;
}

void	set_sprite_type(t_sprite_info *info, char *type)
{
	if (ft_strncmp(type, "wall", 5) == 0)
		set_type(info, 1, 0, 0);
	else if (ft_strncmp(type, "diamond", 7) == 0)
		set_type(info, 0, 1, 0);
	else if (ft_strncmp(type, "player", 7) == 0)
		set_type(info, 0, 0, 0);
	else if (ft_strncmp(type, "exit", 5) == 0)
		set_type(info, 0, 0, 1);
	else if (ft_strncmp(type, "enemy", 6) == 0)
	{
		set_type(info, 0, 0, 0);
		info->enemy = 1;
	}
	else if (ft_strncmp(type, "none", 5) == 0)
		set_type(info, 0, 0, 0);
	else
	{
		ft_putendl_fd("must return sprite type", 2);
		exit(EXIT_FAILURE);
	}
}
