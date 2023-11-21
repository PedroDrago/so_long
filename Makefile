# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:53:51 by pdrago            #+#    #+#              #
#    Updated: 2023/11/21 14:55:07 by pdrago           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long

SRC=so_long.c

all: $(NAME)

$(NAME): $(SRC)
	cc -Wall -Wextra -Werror $(SRC) minilibx-linux/libmlx_Linux.a -lX11 -lXext -o $(NAME)
exec: $(NAME)
	./$(NAME)
