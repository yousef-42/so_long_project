/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:17:07 by yasmail           #+#    #+#             */
/*   Updated: 2026/02/17 18:07:20 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	create_sprite(t_game *game, int index, t_sprite_info info)
{
	int	w;
	int	h;

	game->sprite[index].x = info.x * game->size;
	game->sprite[index].y = info.y * game->size;
	if (!file_exist(info.img))
	{
		perror("failed to open image: ");
		ft_putendl_fd(info.img, 2);
		exit(EXIT_FAILURE);
	}
	game->sprite[index].img = mlx_xpm_file_to_image(game->mlx, info.img, &w,
			&h);
	game->sprite[index].addr = mlx_get_data_addr(game->sprite[index].img,
			&game->sprite[index].bpp, &game->sprite[index].line_length,
			&game->sprite[index].endian);
	game->sprite[index].w = w;
	game->sprite[index].h = h;
	game->sprite[index].collectable = info.collectable;
	game->sprite[index].wall = info.wall;
	game->sprite[index].exit = info.exit;
	game->sprite[index].layer = info.layer;
	game->sprite[index].enemy = info.enemy;
}
