/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:31:32 by yasmail           #+#    #+#             */
/*   Updated: 2026/02/25 19:56:10 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	length_vertical_get(char *map)
{
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			y++;
		i++;
	}
	if (i > 0 && map[i - 1] != '\n')
		y++;
	return (y);
}

static void	give_error(char *error_name, char *map, t_game *game)
{
	ft_printf("%s", error_name);
	if (map)
		free(map);
	exit_handler(game);
}

static void	map_strict_iterate(t_game *game, char *map, int i)
{
	invalid_chars(game, map, i);
	if (map[i] == '\n')
	{
		if (game->map_strict.x < game->length_horizontal
			&& game->map_strict.y != 0)
			give_error("Incorrect length", map, game);
		game->map_strict.x = 0;
		game->map_strict.y++;
	}
	if (game->length_horizontal - 1 < game->map_strict.x
		&& game->map_strict.y != 0)
		give_error("Incorrect length", map, game);
	if (game->map_strict.y == 0)
		game->length_horizontal++;
	if (map[i] != '\n')
		game->map_strict.x++;
	if (map[i] == 'P')
		game->map_strict.player_count++;
}

static void	strict_map(char *map, t_game *game)
{
	int	i;

	i = 0;
	ft_bzero(&game->map_strict, sizeof(game->map_strict));
	game->length_vertical = length_vertical_get(map);
	while (map[i])
	{
		map_strict_iterate(game, map, i);
		if (map[i] == 'E')
			game->map_strict.exit_count++;
		if (map[i] == 'C')
			game->map_strict.collector_count++;
		i++;
	}
	if (game->map_strict.player_count != 1)
		give_error("there must be 1 player in the map", map, game);
	if (game->map_strict.collector_count < 1)
		give_error("there must be at least 1 collector", map, game);
	if (game->map_strict.exit_count != 1)
		give_error("there must be 1 exit in the map", map, game);
	if (game->map_strict.x < game->length_horizontal
		&& game->map_strict.y != 0 && (i > 0 && map[i - 1] != '\n'))
		give_error("Incorrect length", map, game);
	if (game->length_horizontal < 3 || game->length_vertical < 3)
		give_error("Map too small, must contain atleast 3x3", map, game);
}

char	*map_data(char *file_name, t_game *game)
{
	int		map_descriptor;
	char	*map_data_var;
	char	*remained_map;
	char	*temp;

	map_data_var = ft_strdup("");
	map_descriptor = open(file_name, O_RDONLY);
	if (map_descriptor < 0)
		return (NULL);
	remained_map = get_next_line(map_descriptor);
	while (remained_map)
	{
		temp = ft_strjoin(map_data_var, remained_map);
		free(map_data_var);
		map_data_var = temp;
		free(remained_map);
		remained_map = get_next_line(map_descriptor);
	}
	close(map_descriptor);
	strict_map(map_data_var, game);
	path_check(map_data_var, game);
	return (map_data_var);
}
