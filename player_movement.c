/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:04:38 by yasmail           #+#    #+#             */
/*   Updated: 2026/02/26 16:52:28 by yasmail          ###   ########.fr       */
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
				game->input.key_a = 0;
				game->input.key_d = 0;
				game->input.key_w = 0;
				game->input.key_s = 0;
				game->input.ismoving = 0;
				player_idle(game);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

static void	direction_check(t_game *game, int dir_x, int dir_y)
{
	int	target_x;
	int	target_y;

	target_x = 0;
	target_y = 0;
	if (dir_x || dir_y)
	{
		target_x = game->sprite[0].x + dir_x * game->size;
		target_y = game->sprite[0].y + dir_y * game->size;
		if (!contain_wall(game, target_x, target_y))
		{
			game->input.move_x = dir_x;
			game->input.move_y = dir_y;
			game->input.n_tile_x = target_x;
			game->input.n_tile_y = target_y;
			game->input.ismoving = 1;
			player_animation(game, dir_x, dir_y);
		}
		else
		{
			game->input.move_x = 0;
			game->input.move_y = 0;
			game->input.ismoving = 0;
		}
	}
}

static void	not_moved(t_game *game)
{
	int	dir_x;
	int	dir_y;

	dir_x = 0;
	dir_y = 0;
	if (!game->input.ismoving)
	{
		dir_x = game->input.key_d - game->input.key_a;
		dir_y = game->input.key_s - game->input.key_w;
		if (dir_x && dir_y)
			dir_y = 0;
		direction_check(game, dir_x, dir_y);
	}
}

static void	input_movement(t_game *game, double speed)
{
	if (game->input.move_x)
	{
		game->sprite[0].x += game->input.move_x * speed;
		if ((game->input.move_x > 0
				&& game->sprite[0].x >= game->input.n_tile_x)
			|| (game->input.move_x < 0
				&& game->sprite[0].x <= game->input.n_tile_x))
		{
			game->sprite[0].x = game->input.n_tile_x;
			game->input.move_x = 0;
		}
	}
	if (game->input.move_y)
	{
		game->sprite[0].y += game->input.move_y * speed;
		if ((game->input.move_y > 0
				&& game->sprite[0].y >= game->input.n_tile_y)
			|| (game->input.move_y < 0
				&& game->sprite[0].y <= game->input.n_tile_y))
		{
			game->sprite[0].y = game->input.n_tile_y;
			game->input.move_y = 0;
		}
	}
}

void	move_player(t_game *game, double delta)
{
	double	speed;

	speed = 0;
	if (game->cannot_move || game->game_over)
		return ;
	not_moved(game);
	if (game->input.ismoving)
	{
		speed = 100 * delta;
		input_movement(game, speed);
		if (game->input.move_x == 0 && game->input.move_y == 0)
		{
			player_idle(game);
			game->input.ismoving = 0;
			game->movecount++;
			ft_printf("Movements: %d\n", game->movecount);
		}
	}
}
