# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 19:50:18 by pdrago            #+#    #+#              #
#    Updated: 2023/11/16 23:17:58 by pdrago           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME = libft.a 
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
BONUS_SRC = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
PRINTF_SRC = ft_printf/ft_printf.c ft_printf/ft_print_functions.c
GNL_SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)
GNL_OBJ = $(GNL_SRC:.c=.o)

all: $(NAME)

full: $(OBJ) $(BONUS_OBJ) $(PRINTF_OBJ) $(GNL_OBJ)
	ar -rc $(NAME) $(OBJ) $(BONUS_OBJ) $(PRINTF_OBJ) $(GNL_OBJ)

$(NAME): $(OBJ)
	 ar -rc $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ)
	 ar -rc $(NAME) $(OBJ) $(BONUS_OBJ)

printf: $(OBJ) $(PRINTF_OBJ)
	ar -rc $(NAME) $(OBJ) $(PRINTF_OBJ)

gnl: $(OBJ) $(GNL_OBJ)
	ar -rc $(NAME) $(OBJ) $(GNL_OBJ)

.c.o:
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ) $(PRINTF_OBJ) $(GNL_OBJ) a.out

fclean: clean
	rm -f $(NAME)

re: fclean all
