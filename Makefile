# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 17:45:21 by yasmail           #+#    #+#              #
#    Updated: 2026/02/25 18:27:40 by yasmail          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------- Project Name ---------------------- #
NAME = so_long

# ---------------------- Compiler & Flags ------------------ #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include -I mlx -I libft -I get_next_line -I ft_printf

# ---------------------- Source Files ---------------------- #
SRC = main.c \
      get_time.c \
      set_sprite_size.c \
      create_sprite.c \
      set_sprite_info.c \
      file_exist.c \
      set_sprite_type.c \
      draw_sprite_on_canvas.c \
      player_movement.c \
      clear_canvas.c \
      create_map.c \
      create_canvas.c \
      initialize_game.c \
      hitbox_detector.c \
      gem_collect_handler.c \
      close_window.c \
      key_handler.c \
      key_handler_release.c \
      map_data.c \
      gems_left.c \
      open_exit.c \
      found_exit.c \
      change_sprite.c \
      sprite_layer_handler.c \
      exit_handler.c \
      create_background.c \
      free_null.c \
      sprite_animation.c \
      sprite_background_handler.c \
      set_sprite_animation.c \
      create_animation.c \
      player_animation.c \
      player_idle.c \
      text_handler.c \
      anim_name.c \
      enemy_movement.c \
      game_over.c \
      path_check.c \
      invalid_chars.c \
      get_next_line/get_next_line.c \
      get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

# ---------------------- MLX & Libraries ------------------ #
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
MLX  = -lmlx
MLX_PATH = ./mlx
LDFLAGS = -L$(MLX_PATH) -lX11 -lXext -lm

FT_PRINTF_PATH = ft_printf
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a

# ---------------------- Rules ---------------------------- #
all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(FT_PRINTF):
	make -C ft_printf

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(FT_PRINTF) $(MLX) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ---------------------- Cleaning ------------------------ #
clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean
	make -C $(FT_PRINTF_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean
	make -C $(FT_PRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re