/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_canvas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:02:18 by yasmail           #+#    #+#             */
/*   Updated: 2026/02/17 17:50:36 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	create_canvas(t_game *game)
{
	game->canvas.img = mlx_new_image(game->mlx,
			game->width, game->height);
	game->canvas.addr = mlx_get_data_addr(game->canvas.img,
			&game->canvas.bpp,
			&game->canvas.line_length,
			&game->canvas.endian);
	game->canvas.w = game->width;
	game->canvas.h = game->height;
}
