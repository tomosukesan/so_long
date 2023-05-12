# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 10:57:05 by ttachi            #+#    #+#              #
#    Updated: 2023/05/12 16:02:58 by ttachi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra

MLX = -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBFT = libft/libft.a

SRCS = so_long.c \
		so_long_utils.c \
		map/create_strs_map.c \
		map/getstr_from_mapfile.c \
		draw_map.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)
$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJS) $(MLX)

clean:
	$(RM) $(OBJS)
	make clean -C ./libft
fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft
re: fclean all

debug: CFLAGS += -g -fsanitize=address
debug: re

.PHONY: all clean fclean re
