# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wintoo <wintoo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/17 12:54:11 by wintoo            #+#    #+#              #
#    Updated: 2025/11/05 16:31:33 by wintoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC 		= cc
CCFlags = -Wall -Wextra -Werror -g3

SRCS	= src/so_long.c src/map.c src/error.c src/free_it.c src/map_checker.c src/flood_fill.c src/scene.c src/move_player.c \
		utils/get_next_line_utils.c utils/get_next_line.c utils/ft_itoa.c\
		bonus/put_screen_bonus.c bonus/scene_bonus.c bonus/animate_bonus.c bonus/enemy_patrol.c bonus/win_or_lose.c

OBJS	= $(SRCS:.c=.o)

mlxlib 	= mlxlib/build/libmlx42.a -ldl -lglfw -pthread -lm

RM		= rm -rf

all: MLXLIB $(NAME)

MLXLIB:
		@cmake mlxlib -B mlxlib/build && make -C mlxlib/build -j4
	
$(NAME): $(OBJS)
	$(CC) $(CCFlags) $(OBJS) $(mlxlib) -o $@

%.o: %.c
	$(CC) $(CCFlags) -c $< -o $@

clean:
	$(RM) $(OBJS) mlxlib/build

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re