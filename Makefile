# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:53:51 by pdrago            #+#    #+#              #
#    Updated: 2023/11/30 18:32:39 by pdrago           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
FLAGS=-Wall -Wextra -Werror
SRC=so_long.c

all: $(NAME)

$(NAME): $(SRC)
	cc $(SRC) minilibx/libmlx_Linux.a -lX11 -lXext -o $(NAME)
debug: $(SRC)
	cc -g $(SRC) minilibx/libmlx_Linux.a -lX11 -lXext -o $(NAME)
	lldb ./$(NAME)

exec: $(NAME)
	./$(NAME)
test:
	@cc $(SRC) minilibx/libmlx_Linux.a -lX11 -lXext -o $(NAME)
	./$(NAME)
clean:
	rm -f $(NAME)
fclean: clean

re: fclean all
