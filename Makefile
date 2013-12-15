CC = gcc
NAME = hotrace
SRC = get_next_line.c ft_strdup.c ft_memcpy.c ft_strlen.c ft_putchar.c  \
	ft_putstr.c ft_strcmp.c\
	main.c  t_search.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

