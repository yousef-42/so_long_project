/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:10:48 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/06 18:05:25 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	change_sprite(t_game *game, int index, char *image)
{
	if (game->sprite[index].img)
	{
		mlx_destroy_image(game->mlx, game->sprite[index].img);
		game->sprite[index].img = NULL;
	}
	game->sprite[index].w = 0;
	game->sprite[index].h = 0;
	game->sprite[index].addr = NULL;
	game->sprite[index].img = mlx_xpm_file_to_image(game->mlx,
			image, &game->sprite[index].w,
			&game->sprite[index].h);
	if (game->sprite[index].img)
		game->sprite[index].addr = mlx_get_data_addr(game->sprite[index].img,
				&game->sprite[index].bpp,
				&game->sprite[index].line_length,
				&game->sprite[index].endian);
}
