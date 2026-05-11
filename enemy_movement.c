/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 21:37:19 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/28 17:14:05 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	contain_wall(t_game *game, int tileX, int tileY)
{
	int	i;

	i = 0;
	while (i < game->count_sprite)
	{
		if (game->sprite[i].wall)
		{
			if (game->sprite[i].x == tileX && game->sprite[i].y == tileY)
			{
				if (game->sprite[i].exit)
					ft_printf("you must collect all the gems first\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void	move_horizontal(t_game *game, int i, double speed)
{
	int	next_x;
	int	next_y;

	next_x = game->sprite[i].x + game->sprite[i].dir_x * game->size;
	next_y = game->sprite[i].y;
	if (game->sprite[i].dir_x < 0)
	{
		create_animation(game, i, anim_name("Images/enemy/left/", 10), 0.1);
		set_sprite_animation(game, i, 0, 0);
	}
	else
	{
		create_animation(game, i, anim_name("Images/enemy/right/", 10), 0.1);
		set_sprite_animation(game, i, 0, 0);
	}
	if (contain_wall(game, next_x, next_y))
		game->sprite[i].dir_x *= -1;
	next_x = game->sprite[i].x + game->sprite[i].dir_x * game->size;
	game->sprite[i].x += game->sprite[i].dir_x * speed;
	if ((game->sprite[i].dir_x > 0 && game->sprite[i].x > next_x)
		|| (game->sprite[i].dir_x < 0 && game->sprite[i].x < next_x))
		game->sprite[i].x = next_x;
}

void	move_vertical(t_game *game, int i, double speed)
{
	int	next_x;
	int	next_y;

	next_x = game->sprite[i].x;
	next_y = game->sprite[i].y + game->sprite[i].dir_y * game->size;
	if (game->sprite[i].dir_y < 0)
	{
		create_animation(game, i, anim_name("Images/enemy/up/", 10), 0.1);
		set_sprite_animation(game, i, 0, 0);
	}
	else
	{
		create_animation(game, i, anim_name("Images/enemy/down/", 10), 0.1);
		set_sprite_animation(game, i, 0, 0);
	}
	if (contain_wall(game, next_x, next_y))
		game->sprite[i].dir_y *= -1;
	next_y = game->sprite[i].y + game->sprite[i].dir_y * game->size;
	game->sprite[i].y += game->sprite[i].dir_y * speed;
	if ((game->sprite[i].dir_y > 0 && game->sprite[i].y > next_y)
		|| (game->sprite[i].dir_y < 0 && game->sprite[i].y < next_y))
		game->sprite[i].y = next_y;
}

void	move_enemy(t_game *game, double delta)
{
	double	speed;
	int		i;

	speed = 100 * delta;
	i = 0;
	while (i < game->count_sprite)
	{
		if (game->sprite[i].enemy)
		{
			if (game->sprite[i].is_horiz)
				move_horizontal(game, i, speed);
			else
				move_vertical(game, i, speed);
		}
		i++;
	}
}
