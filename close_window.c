/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:39:25 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/06 18:07:51 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	exit_handler(game);
	return (0);
}
