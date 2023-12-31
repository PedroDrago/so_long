# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:53:51 by pdrago            #+#    #+#              #
#    Updated: 2023/12/08 16:25:49 by pdrago           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
FLAGS=-Wall -Wextra -Werror
SRCDIR=src
UTILSDIR=$(SRCDIR)/utils
GNLDIR=$(UTILSDIR)/get_next_line
SRC=$(SRCDIR)/end_game.c $(SRCDIR)/attack.c $(SRCDIR)/enemy.c $(SRCDIR)/lettering.c $(SRCDIR)/movements_utils.c $(UTILSDIR)/ft_itoa.c $(SRCDIR)/hooks.c $(SRCDIR)/map.c $(SRCDIR)/map_checkers.c $(SRCDIR)/map_utils.c $(SRCDIR)/movements.c $(SRCDIR)/path_checker.c $(SRCDIR)/renders.c $(SRCDIR)/so_long.c $(SRCDIR)/sprites.c $(SRCDIR)/validations.c $(UTILSDIR)/ft_printf.c $(UTILSDIR)/ft_putchar_fd.c $(UTILSDIR)/ft_putstr_fd.c $(UTILSDIR)/ft_strchr.c $(UTILSDIR)/ft_strlen.c $(UTILSDIR)/ft_strnstr.c $(GNLDIR)/get_next_line.c  $(GNLDIR)/get_next_line_utils.c
RED=\e[31m
GREEN=\e[32m
ENDCOLOR=\e[0m
MAPDIR = maps
MAP=$(MAPDIR)/$(M).ber
M=map
MINILIBX=minilibx/
LEAKTESTER=so_long_leaktester/

all: $(NAME)

setup: $(MINILIBX)

$(NAME): $(SRC) $(MINILIBX)
	@cc $(FLAGS) $(SRC) minilibx/libmlx_Linux.a -lX11 -lXext -o $(NAME)
	@echo "$(GREEN)finished compiling so_long$(ENDCOLOR)"

$(MINILIBX):
	@echo "$(GREEN)Installing minilibx$(ENDCOLOR)"
	@git clone https://github.com/42Paris/minilibx-linux.git minilibx && cd minilibx && make && cd ..
	@make

$(LEAKTESTER):
	@echo "$(GREEN)Downloading so_long_leaktester:$(ENDCOLOR)"
	@git clone git@github.com:PedroDrago/so_long_leaktester.git

debug: $(SRC)
	@clang $(FLAGS) -g $(SRC) minilibx/libmlx_Linux.a -lX11 -lXext -o $(NAME)
	@echo "$(GREEN)Entering lldb for so_long debugging:$(ENDCOLOR)"
	@lldb ./$(NAME) $(MAP)

play: $(NAME)
	@echo "$(GREEN)Executing so_long:$(ENDCOLOR)"
	./play

leak: $(NAME) $(LEAKTESTER)
	@echo "$(GREEN)Executing so_long_leaktester:$(ENDCOLOR)"
	@cd so_long_leaktester && make

clean:
	@rm -f $(NAME)
	@echo "$(GREEN)Finished cleaning so_long$(ENDCOLOR)"

fclean: clean
	@rm -rf $(LEAKTESTER)
	@echo "$(GREEN)Finished fcleaning so_long$(ENDCOLOR)"

re: fclean all

.PHONY: all clean fclean play leak
