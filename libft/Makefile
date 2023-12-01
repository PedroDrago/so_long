# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 19:50:18 by pdrago            #+#    #+#              #
#    Updated: 2023/12/01 01:11:38 by pdrago           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME = libft.a 
SRC = ft_atoi.c ft_printf.c ft_strupper.c ft_strlower.c ft_strchr_idx.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
BONUS_SRC = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
GNL_SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
GNL_OBJ = $(GNL_SRC:.c=.o)

RED=\e[31m
GREEN=\e[32m
ENDCOLOR=\e[0m

all: full

full: $(OBJ) $(BONUS_OBJ) $(GNL_OBJ)
	@ar -rc $(NAME) $(OBJ) $(BONUS_OBJ) $(GNL_OBJ)
	@echo "$(GREEN)finished compiling libft$(ENDCOLOR)"

$(NAME): $(OBJ)
	 @ar -rc $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ)
	@ar -rc $(NAME) $(OBJ) $(BONUS_OBJ)

gnl: $(OBJ) $(GNL_OBJ)
	@ar -rc $(NAME) $(OBJ) $(GNL_OBJ)

.c.o:
	@cc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(BONUS_OBJ) $(GNL_OBJ) a.out

fclean: clean
	@rm -f $(NAME)

re: fclean all
