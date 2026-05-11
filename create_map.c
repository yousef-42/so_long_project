/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:27:27 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/07 19:05:42 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	set_map_one(t_game *game, t_sprite_info *info, char map, int *index)
{
	if (map == '1')
	{
		set_sprite_info(info, "Images/wall.xpm", info->x, info->y);
		set_sprite_type(info, "wall");
		info->layer = 2;
		create_sprite(game, index[0], *info);
		(*index)++;
	}
	else if (map == 'P')
	{
		set_sprite_info(info, "Images/idle/down/1.xpm", info->x, info->y);
		set_sprite_type(info, "player");
		info->layer = 1;
		create_sprite(game, 0, *info);
		create_animation(game, 0, anim_name("Images/idle/down/", 2), 0.3);
		set_sprite_animation(game, 0, 0, 0);
	}
	else if (map == 'E')
	{
		set_sprite_info(info, "Images/door/1.xpm", info->x, info->y);
		set_sprite_type(info, "exit");
		info->layer = 0;
		create_sprite(game, index[0], *info);
		(*index)++;
	}
}

static void	set_map_two(t_game *game, t_sprite_info *info, char map, int *index)
{
	if (map == '3')
	{
		set_sprite_info(info, "Images/coin/1.xpm", info->x, info->y);
		set_sprite_type(info, "enemy");
		create_sprite(game, index[0], *info);
		game->sprite[index[0]].dir_x = 1;
		game->sprite[index[0]].dir_y = 1;
		create_animation(game, index[0], anim_name("Images/enemy/down/", 10),
			0.1);
		set_sprite_animation(game, index[0], 0, 0);
		(*index)++;
	}
	else if (map == '4')
	{
		set_sprite_info(info, "Images/coin/1.xpm", info->x, info->y);
		set_sprite_type(info, "enemy");
		create_sprite(game, index[0], *info);
		game->sprite[index[0]].dir_x = 1;
		game->sprite[index[0]].dir_y = 1;
		create_animation(game, index[0], anim_name("Images/enemy/right/", 10),
			0.1);
		set_sprite_animation(game, index[0], 0, 0);
		game->sprite[index[0]].is_horiz = 1;
		(*index)++;
	}
}

static void	set_map_three(t_game *game, t_sprite_info *info, char map,
		int *index)
{
	if (map == 'C')
	{
		set_sprite_info(info, "Images/coin/1.xpm", info->x, info->y);
		set_sprite_type(info, "diamond");
		info->layer = 4;
		create_sprite(game, index[0], *info);
		create_animation(game, index[0], anim_name("Images/coin/", 10), 0.1);
		set_sprite_animation(game, index[0], 0, 0);
		(*index)++;
	}
}

static void	initialize_map(t_sprite_info *info)
{
	info->x = 0;
	info->y = 0;
	info->wall = 0;
	info->collectable = 0;
	info->enemy = 0;
}

void	create_map(t_game *game, t_sprite_info *info, char *map)
{
	int	js;
	int	index;
	int	*index_global;

	js = 0;
	index = 1;
	index_global = &index;
	initialize_map(info);
	while (map[js])
	{
		if (map[js] == '\n')
		{
			info->y++;
			info->x = 0;
		}
		set_map_one(game, info, map[js], index_global);
		set_map_two(game, info, map[js], index_global);
		set_map_three(game, info, map[js], index_global);
		if (map[js] != '\n')
			info->x++;
		js++;
	}
}
