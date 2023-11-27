# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:53:51 by pdrago            #+#    #+#              #
#    Updated: 2023/11/27 00:36:46 by pdrago           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long

SRC=so_long.c

all: $(NAME)

$(NAME): $(SRC)
	cc -Wall -Wextra -Werror $(SRC) minilibx/libmlx_Linux.a -lX11 -lXext -o $(NAME)
exec: $(NAME)
	./$(NAME)
test:
	@cc $(SRC) minilibx/libmlx_Linux.a -lX11 -lXext -o $(NAME)
	./$(NAME)
