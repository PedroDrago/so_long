# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:53:51 by pdrago            #+#    #+#              #
#    Updated: 2023/12/03 07:54:13 by pdrago           ###   ########.fr        #
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
MAP=map.ber

all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
	@cc $(SRC) $(LIBFT) minilibx/libmlx_Linux.a -lX11 -lXext -o $(NAME)
	@echo "$(GREEN)finished compiling so_long$(ENDCOLOR)"

debug: $(SRC)
	@cc -g $(SRC) $(LIBFT) minilibx/libmlx_Linux.a -lX11 -lXext -o $(NAME)
	@echo "$(GREEN)Entering lldb for so_long debugging:$(ENDCOLOR)"
	@lldb ./$(NAME) $(MAP)

exec: $(NAME)
	@echo "$(GREEN)Executing so_long:$(ENDCOLOR)"
	@./$(NAME) $(MAP)

$(LIBFT):
	@cd libft && make

clean:
	@rm -f $(NAME) && cd libft && make clean

fclean: clean
	@cd libft && make fclean

re: fclean all
