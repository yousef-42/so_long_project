/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_canvas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:03:09 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/06 18:07:26 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	clear_canvas(t_sprite *canvas, unsigned int color)
{
	unsigned int	*pixels;
	int				total;
	int				i;

	i = 0;
	if (!canvas || !canvas->addr)
		return ;
	pixels = (unsigned int *)canvas->addr;
	total = canvas->w * canvas->h;
	while (i < total)
	{
		pixels[i] = color;
		i++;
	}
}
