/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:23:01 by yasmail           #+#    #+#             */
/*   Updated: 2026/02/25 19:45:31 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	valid_chars(char mp)
{
	return (mp == 'E' || mp == 'P' || mp == '0' || mp == '1' || mp == 'C'
		|| mp == '3' || mp == '4' || mp == '\n');
}

static void	give_error(char *error_name, char *map, t_game *game)
{
	if (map)
		free(map);
	ft_printf("%s\n", error_name);
	exit_handler(game);
}

void	invalid_chars(t_game *game, char *map_data, int index)
{
	if (map_data[index] == ' ')
		give_error("empty component (add 0 not ' ')", map_data, game);
	if ((map_data[index] != '1' && map_data[index] != '\n')
		&& (game->map_strict.y == 0
			|| game->map_strict.y == game->length_vertical - 1))
		give_error("invalid bound", map_data, game);
	if ((map_data[index] != '1' && map_data[index] != '\n')
		&& (game->map_strict.x == 0
			|| game->map_strict.x == game->length_horizontal - 1))
		give_error("invalid bound", map_data, game);
	if (!valid_chars(map_data[index]))
	{
		ft_printf("%c doesn't exist in map data\n", map_data[index]);
		if (map_data)
			free(map_data);
		exit_handler(game);
	}
}
