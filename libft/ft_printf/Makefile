NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
MAIN = testes/main.c
SRC = ft_printf.c ft_print_functions.c 
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
