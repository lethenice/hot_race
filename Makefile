CC = gcc
NAME = hotrace
SRC = get_next_line.c ft_strdup.c ft_memcpy.c ft_strlen.c ft_putchar.c  \
	ft_putstr.c ft_strcmp.c t_search2.c\
	main.c  t_search.c \
	get_value.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -g

%.o: %.c
	$(CC) -c $^ -o $@ $(CFLAGS) -g

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

