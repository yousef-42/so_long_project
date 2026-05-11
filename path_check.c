/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:58:51 by yasmail           #+#    #+#             */
/*   Updated: 2026/05/02 15:30:25 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	give_error(char *error_name, char *map, t_game *game)
{
	ft_printf("%s", error_name);
	if (map)
		free(map);
	exit_handler(game);
}

static void	flood_fill(char *map, t_game *game, int x, int y)
{
	int	index;

	if (x < 0 || y < 0 || x >= game->length_horizontal
		|| y >= game->length_vertical)
		return ;
	index = y * (game->length_horizontal + 1) + x;
	if (map[index] == '1' || map[index] == 'V')
		return ;
	map[index] = 'V';
	flood_fill(map, game, x + 1, y);
	flood_fill(map, game, x - 1, y);
	flood_fill(map, game, x, y + 1);
	flood_fill(map, game, x, y - 1);
}

static void	find_player(char *map, int *px, int *py)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (map[i])
	{
		if (map[i] == 'P')
		{
			*px = x;
			*py = y;
			return ;
		}
		if (map[i] == '\n')
		{
			y++;
			x = 0;
		}
		else
			x++;
		i++;
	}
}

static void	validate_path(char *map, t_game *game, char *main_map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'C' || map[i] == 'E')
		{
			if (map)
				free(map);
			give_error("No valid path in map\n", main_map, game);
		}
		i++;
	}
}

void	path_check(char *map, t_game *game)
{
	char	*map_copy;
	int		player_x;
	int		player_y;

	map_copy = ft_strdup(map);
	if (!map_copy)
		return ;
	find_player(map_copy, &player_x, &player_y);
	flood_fill(map_copy, game, player_x, player_y);
	validate_path(map_copy, game, map);
	free(map_copy);
}
