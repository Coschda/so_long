# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 19:09:53 by mdoumi            #+#    #+#              #
#    Updated: 2022/11/08 12:24:34 by mdoumi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS =	ft_printf.c	utils.c utils2.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	gcc -Wall -Wextra -Werror -c ${SRCS}
	ar rc ${NAME} ${OBJS} libftprintf.h

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
