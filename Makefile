# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:53:51 by pdrago            #+#    #+#              #
#    Updated: 2023/12/01 01:11:30 by pdrago           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
FLAGS=-Wall -Wextra -Werror
SRCDIR = src
SRC= src/so_long.c src/hooks.c src/map.c
LIBFT=libft/libft.a
RED=\e[31m
GREEN=\e[32m
ENDCOLOR=\e[0m

all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
	@cc $(SRC) $(LIBFT) minilibx/libmlx_Linux.a -lX11 -lXext -o $(NAME)
	@echo "$(GREEN)finished compiling so_long$(ENDCOLOR)"

debug: $(SRC)
	@cc -g $(SRC) $(LIBFT) minilibx/libmlx_Linux.a -lX11 -lXext -o $(NAME)
	@echo "$(GREEN)Entering lldb for so_long debugging:$(ENDCOLOR)"
	@lldb ./$(NAME)

exec: $(NAME)
	@echo "$(GREEN)Executing so_long:$(ENDCOLOR)"
	@./$(NAME)

$(LIBFT):
	@cd libft && make

clean:
	@rm -f $(NAME) && cd libft && make clean

fclean: clean
	@cd libft && make fclean

re: fclean all
