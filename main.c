/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:33:30 by yasmail           #+#    #+#             */
/*   Updated: 2026/05/04 15:12:52 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// update loop
static int	update(void *param)
{
	t_game	*game;
	double	now;
	double	dt;

	game = (t_game *)param;
	now = get_time();
	dt = now - game->last_update;
	game->last_update = now;
	move_player(game, dt);
	move_enemy(game, dt);
	gem_collect_handler(game);
	if (!gems_left(game))
		open_exit(game);
	clear_canvas(&game->canvas, 0x00000000);
	sprite_background_handler(game);
	sprite_animation(game, dt);
	draw_sprite_on_canvas(&game->canvas, &game->background_canvas);
	sprite_layer_handler(game, 5);
	found_exit(game, dt);
	enemy_touched(game, dt);
	mlx_put_image_to_window(game->mlx, game->window, game->canvas.img, 0, 0);
	text_handler(game);
	game->initialized_delta = 1;
	return (0);
}

static int	input_map_check(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("invalid: give map name\n");
		return (1);
	}
	if (!file_exist(argv[1]))
	{
		ft_printf("no file named: %s\n", argv[1]);
		return (1);
	}
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
	{
		ft_printf("file type must end with .ber\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game			game;
	t_sprite_info	info;

	if (input_map_check(argc, argv))
		return (2);
	ft_bzero(&game, sizeof(t_game));
	game.sprite = NULL;
	game.size = 32;
	game.map = map_data(argv[1], &game);
	initialize_game(&game, "MLX Test");
	game.coins_left = game.map_strict.collector_count;
	set_sprite_size(&game, game.map);
	create_map(&game, &info, game.map);
	create_background(&game, &info, game.map);
	create_canvas(&game);
	mlx_hook(game.window, 17, 0, close_window, &game);
	mlx_hook(game.window, 2, 1L << 0, handle_key, &game);
	mlx_hook(game.window, 3, 1L << 1, handle_key_release, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
	return (0);
}
