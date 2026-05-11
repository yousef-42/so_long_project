/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_on_canvas.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:36:15 by yasmail           #+#    #+#             */
/*   Updated: 2026/02/17 18:02:18 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	bound_check(int dst_x, t_sprite *canvas, int *x)
{
	if (dst_x < 0 || dst_x >= canvas->w)
	{
		(*x)++;
		return (1);
	}
	else
		return (0);
}

static int	skip_transparent(unsigned int color, int *x)
{
	if ((color & 0x00FFFFFF) == 0)
	{
		(*x)++;
		return (1);
	}
	else
		return (0);
}

static void	draw_iterate(t_sprite *canvas, t_sprite *sprite, int y, int dst_y)
{
	int				*x;
	char			*src;
	unsigned int	color;
	char			*dst;
	int				dst_x;

	x = malloc(sizeof(int));
	if (!x)
		return ;
	ft_bzero(x, sizeof(int));
	while (*x < sprite->w)
	{
		dst_x = sprite->x + *x;
		if (bound_check(dst_x, canvas, x))
			continue ;
		src = sprite->addr + y * sprite->line_length + *x * (sprite->bpp / 8);
		color = *(unsigned int *)src;
		if (skip_transparent(color, x))
			continue ;
		dst = canvas->addr + dst_y * canvas->line_length + dst_x * (canvas->bpp
				/ 8);
		*(unsigned int *)dst = color;
		(*x)++;
	}
	free(x);
}

void	draw_sprite_on_canvas(t_sprite *canvas, t_sprite *sprite)
{
	int	y;
	int	dst_y;

	y = 0;
	while (y < sprite->h)
	{
		dst_y = sprite->y + y;
		if (dst_y < 0 || dst_y >= canvas->h)
		{
			y++;
			continue ;
		}
		draw_iterate(canvas, sprite, y, dst_y);
		y++;
	}
}
