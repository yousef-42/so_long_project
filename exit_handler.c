/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:28:26 by yasmail           #+#    #+#             */
/*   Updated: 2026/02/25 18:31:18 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	free_animation(char **anima)
{
	size_t	j;

	j = 0;
	if (!anima)
		return ;
	while (anima[j])
	{
		free(anima[j]);
		j++;
	}
	if (anima)
		free(anima);
}

static void	remove_sprites(t_game *game)
{
	int	i;

	i = 0;
	if (game->sprite)
	{
		while (i < game->count_sprite)
		{
			if (game->sprite[i].animation_img)
				free_animation(game->sprite[i].animation_img);
			if (game->sprite[i].img)
			{
				mlx_destroy_image(game->mlx, game->sprite[i].img);
				game->sprite[i].img = NULL;
			}
			i++;
		}
		free(game->sprite);
		game->sprite = NULL;
	}
}

static void	remove_background(t_game *game)
{
	int	i;

	i = 0;
	if (game->sprite_background)
	{
		while (i < game->count_sprite_background)
		{
			if (game->sprite_background[i].img)
			{
				mlx_destroy_image(game->mlx, game->sprite_background[i].img);
				game->sprite_background[i].img = NULL;
			}
			i++;
		}
		free(game->sprite_background);
		game->sprite_background = NULL;
	}
}

static void	free_map(t_game *game)
{
	if (game->map)
	{
		free(game->map);
		game->map = NULL;
	}
}

void	exit_handler(t_game *game)
{
	remove_sprites(game);
	remove_background(game);
	free_map(game);
	if (game->window)
	{
		mlx_destroy_window(game->mlx, game->window);
		game->window = NULL;
	}
	if (game->canvas.img)
	{
		mlx_destroy_image(game->mlx, game->canvas.img);
		game->canvas.img = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}
