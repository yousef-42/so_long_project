# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 16:47:29 by yasmail           #+#    #+#              #
#    Updated: 2025/12/29 17:59:59 by yasmail          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFTDIRECTORY = ./libft

SRCS = 	ft_printf.c \
		print_pointer.c \
		ft_ultoa_hex.c \
		ft_uitoa.c \
		ft_putchar_fd_checked.c \
		ft_putstr_fd_checked.c \
		ft_itoa_check.c	\
		ft_string_check.c \
		ft_uitoa_check.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIRECTORY)
	@cp $(LIBFTDIRECTORY)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	@ar -r $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIRECTORY) && make clean
	
fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIRECTORY) && make fclean
	
re: fclean all

.PHONY: all clean fclean re makelibft