/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:10:54 by yasmail           #+#    #+#             */
/*   Updated: 2026/02/17 18:07:17 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	initiallize_var(t_sprite_info *info)
{
	info->x = 0;
	info->y = 0;
	info->wall = 0;
	info->collectable = 0;
	info->enemy = 0;
}

static void	create_sprite_background(t_game *game, int index,
		t_sprite_info info)
{
	int	w;
	int	h;

	game->sprite_background[index].x = info.x * game->size;
	game->sprite_background[index].y = info.y * game->size;
	if (!file_exist(info.img))
	{
		perror("failed to open image: ");
		ft_putendl_fd(info.img, 2);
		exit(EXIT_FAILURE);
	}
	game->sprite_background[index].img = mlx_xpm_file_to_image(game->mlx,
			info.img, &w, &h);
	game->sprite_background[index].addr
		= mlx_get_data_addr(game->sprite_background[index].img,
			&game->sprite_background[index].bpp,
			&game->sprite_background[index].line_length,
			&game->sprite_background[index].endian);
	game->sprite_background[index].w = w;
	game->sprite_background[index].h = h;
	game->sprite_background[index].collectable = info.collectable;
	game->sprite_background[index].wall = info.wall;
	game->sprite_background[index].exit = info.exit;
	game->sprite_background[index].layer = info.layer;
}

static void	set_sprite(t_game *game, t_sprite_info *info, int index)
{
	set_sprite_info(info, "Images/background.xpm", info->x, info->y);
	set_sprite_type(info, "none");
	info->layer = 0;
	create_sprite_background(game, index, *info);
	info->x++;
}

void	create_background(t_game *game, t_sprite_info *info, char *map)
{
	int	js;
	int	index;

	js = 0;
	index = 0;
	initiallize_var(info);
	while (map[js])
	{
		if (map[js] == '\n')
		{
			info->y++;
			info->x = 0;
		}
		else
		{
			set_sprite(game, info, index);
			index++;
		}
		js++;
	}
}
