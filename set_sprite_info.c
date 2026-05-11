/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:43:42 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/07 18:41:51 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	set_sprite_info(t_sprite_info *info, char *image, int x, int y)
{
	info->img = image;
	info->x = x;
	info->y = y;
}
