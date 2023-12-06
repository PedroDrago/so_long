# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:53:51 by pdrago            #+#    #+#              #
#    Updated: 2023/12/06 11:49:19 by pdrago           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
FLAGS=-Wall -Wextra -Werror
# SRC= src/*.c #fix wild cards
SRC= src/end_game.c src/hooks.c src/map.c src/map_checkers.c src/map_utils.c src/movements.c src/path_checker.c src/renders.c src/so_long.c src/sprites.c src/validations.c src/utils/ft_printf.c src/utils/ft_putchar_fd.c src/utils/ft_putstr_fd.c src/utils/ft_strchr.c src/utils/ft_strlen.c src/utils/ft_strnstr.c src/utils/get_next_line/get_next_line.c  src/utils/get_next_line/get_next_line_utils.c
RED=\e[31m
GREEN=\e[32m
ENDCOLOR=\e[0m
MAPDIR = maps
MAP=$(MAPDIR)/$(M).ber
M=map
CC=clang

all: $(NAME)

$(NAME): $(SRC)
	@cc $(FLAGS) $(SRC) minilibx/libmlx_Linux.a -lX11 -lXext -o $(NAME)
	@echo "$(GREEN)finished compiling so_long$(ENDCOLOR)"

debug: $(SRC)
	@$(CC) $(FLAGS) -g $(SRC) minilibx/libmlx_Linux.a -lX11 -lXext -o $(NAME)
	@echo "$(GREEN)Entering lldb for so_long debugging:$(ENDCOLOR)"
	@lldb ./$(NAME) $(MAP)

exec: $(NAME)
	@echo "$(GREEN)Executing so_long:$(ENDCOLOR)"
	@./$(NAME) $(MAP)

clean:
	@rm -f $(NAME)
	@echo "$(GREEN)Finished cleaning so_long$(ENDCOLOR)"

fclean: clean
	@echo "$(GREEN)Finished fcleaning so_long$(ENDCOLOR)"

re: fclean all

.PHONY: all clean fclean re exec
