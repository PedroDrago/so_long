# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:53:51 by pdrago            #+#    #+#              #
#    Updated: 2023/11/30 23:54:16 by pdrago           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
FLAGS=-Wall -Wextra -Werror
SRCDIR = src
SRC= src/so_long.c src/hooks.c src/utils/ft_printf.c
LIBFT=libft/libft.a

all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
	cc $(SRC) $(LIBFT) minilibx/libmlx_Linux.a -lX11 -lXext -o $(NAME)

debug: $(SRC)
	cc -g $(SRC) $(LIBFT) minilibx/libmlx_Linux.a -lX11 -lXext -o $(NAME)
	lldb ./$(NAME)

exec: $(NAME)
	./$(NAME)

test:
	@cc $(SRC) ($LIBFT) minilibx/libmlx_Linux.a -lX11 -lXext -o $(NAME)
	./$(NAME)

$(LIBFT):
	cd libft && make

clean:
	rm -f $(NAME) && cd libft && make clean

fclean: clean
	cd libft && make fclean

re: fclean all
