/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:39:06 by yasmail           #+#    #+#             */
/*   Updated: 2026/02/25 19:03:25 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

# define KEY_MAX 65536

# ifdef __APPLE__
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_UP 126
#  define KEY_LEFT 123
#  define KEY_DOWN 125
#  define KEY_RIGHT 124
# elif defined(__linux__)
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_UP 65362
#  define KEY_LEFT 65361
#  define KEY_DOWN 65364
#  define KEY_RIGHT 65363
# endif

typedef struct s_input
{
	int				key_w;
	int				key_a;
	int				key_s;
	int				key_d;
	int				key_pressed_w;
	int				key_pressed_a;
	int				key_pressed_s;
	int				key_pressed_d;
	int				ismoving;
	double			n_tile_x;
	double			n_tile_y;
	int				move_x;
	int				move_y;
}					t_input;

typedef struct s_sprite
{
	void			*img;
	char			*addr;
	int				w;
	int				h;
	int				bpp;
	int				line_length;
	int				endian;
	double			x;
	double			y;
	int				dir_x;
	int				dir_y;
	int				wall;
	int				collectable;
	int				enemy;
	int				layer;
	int				exit;
	double			animation_timer;
	char			**animation_img;
	int				frame;
	int				no_loop;
	int				started;
	int				is_same_anim;
	int				is_horiz;
	double			speed;
}					t_sprite;

typedef struct s_sprite_info
{
	void			*img;
	int				x;
	int				y;
	int				wall;
	int				collectable;
	int				exit;
	int				layer;
	int				enemy;
}					t_sprite_info;

typedef struct s_map_strict
{
	int				x;
	int				y;
	int				player_count;
	int				exit_count;
	int				collector_count;
}					t_map_strict;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	int				width;
	int				height;
	int				size;
	int				length_horizontal;
	int				length_vertical;
	int				count_sprite;
	int				count_sprite_background;
	t_sprite		background_canvas;
	t_input			input;
	t_sprite		*sprite;
	t_sprite		*sprite_background;
	t_sprite		canvas;
	t_map_strict	map_strict;
	int				movecount;
	char			*map;
	double			last_update;
	int				initialized_delta;
	int				wall_detected;
	int				cannot_move;
	int				coins_left;
	double			win_timer;
	double			game_over_timer;
	int				game_win;
	int				game_over;
	int				exit_met;
	int				key_state[KEY_MAX];
}					t_game;

double				get_time(void);
void				set_sprite_size(t_game *game, char *map);
void				create_sprite(t_game *game, int index, t_sprite_info info);
void				set_sprite_info(t_sprite_info *info, char *image, int x,
						int y);
int					file_exist(const char *path);
void				set_sprite_type(t_sprite_info *info, char *type);
void				draw_sprite_on_canvas(t_sprite *canvas, t_sprite *sprite);
void				move_player(t_game *game, double delta);
void				clear_canvas(t_sprite *canvas, unsigned int color);
void				create_map(t_game *game, t_sprite_info *info, char *map);
void				create_canvas(t_game *game);
void				initialize_game(t_game *game, char *gameName);
int					hitbox_detect(t_sprite *a, t_sprite *b);
void				gem_collect_handler(t_game *game);
int					close_window(void *param);
int					handle_key(int keycode, void *param);
int					handle_key_release(int keycode, void *param);
char				*map_data(char *file_name, t_game *game);
int					gems_left(t_game *game);
void				open_exit(t_game *game);
void				found_exit(t_game *game, double delta);
void				change_sprite(t_game *game, int index, char *image);
void				sprite_layer_handler(t_game *game, int max_layer);
void				exit_handler(t_game *game);
void				create_background(t_game *game, t_sprite_info *info,
						char *map);
void				draw_sprite_on_canvas_bg(t_sprite *canvas,
						t_sprite *sprite);
void				free_null(void **ptr);
void				sprite_animation(t_game *game, double delta);
void				sprite_background_handler(t_game *game);
void				set_sprite_animation(t_game *game, int index, int force,
						int no_loop);
void				player_animation(t_game *game, int x_side, int y_side);
void				player_idle(t_game *game);
void				create_animation(t_game *game, int index, char **anima,
						double speed);
void				text_handler(t_game *game);
char				**anim_name(char *directory, int indicies);
void				move_enemy(t_game *game, double delta);
void				enemy_touched(t_game *game, double delta);
void				path_check(char *map, t_game *game);
void				invalid_chars(t_game *game, char *map_data, int index);
#endif
