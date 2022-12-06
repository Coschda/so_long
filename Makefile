# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 13:44:41 by mdoumi            #+#    #+#              #
#    Updated: 2022/12/06 09:07:40 by mdoumi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	srcs/main.c \
		srcs/utils.c \
		srcs/utils2.c \
		srcs/render.c \
		srcs/check_maps.c \
		srcs/check_maps2.c \
		srcs/check_possible.c \
		srcs/can_move.c \
		srcs/game_utils.c \
		get_next_line/get_next_line_bonus.c \
		get_next_line/get_next_line_utils_bonus.c \
		ft_printf/ft_printf.c \
		ft_printf/utils.c \
		ft_printf/utils2.c

GCC = gcc -Wall -Wextra -Werror

$(NAME):
	$(GCC) $(SRCS) -o $(NAME) libmlx42.a -I include -lglfw -L "/Users/mdoumi/.brew/opt/glfw/lib/"

all: $(NAME)

clean:
	rm -rf ${OBJS}

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
