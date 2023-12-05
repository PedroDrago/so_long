# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:53:51 by pdrago            #+#    #+#              #
#    Updated: 2023/12/05 11:25:31 by pdrago           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
FLAGS=-Wall -Wextra -Werror
SRCDIR = src
SRC= src/*.c #fix wild cards
LIBFT=libft/libft.a
RED=\e[31m
GREEN=\e[32m
ENDCOLOR=\e[0m
MAPDIR = maps
MAP=$(MAPDIR)/$(M).ber
M=map
CC=clang

all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
	@cc $(FLAGS) $(SRC) $(LIBFT) minilibx/libmlx_Linux.a -lX11 -lXext -o $(NAME)
	@echo "$(GREEN)finished compiling so_long$(ENDCOLOR)"

debug: $(SRC)
	@cc $(FLAGS) -g $(SRC) $(LIBFT) minilibx/libmlx_Linux.a -lX11 -lXext -o $(NAME)
	@echo "$(GREEN)Entering lldb for so_long debugging:$(ENDCOLOR)"
	@lldb ./$(NAME) $(MAP)

exec: $(NAME)
	@echo "$(GREEN)Executing so_long:$(ENDCOLOR)"
	@./$(NAME) $(MAP)

$(LIBFT):
	@cd libft && make

clean:
	@rm -f $(NAME) && cd libft && make clean
	@echo "$(GREEN)Finished cleaning so_long$(ENDCOLOR)"

fclean: clean
	@echo "$(GREEN)Finished fcleaning so_long$(ENDCOLOR)"
	@cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re exec debug
