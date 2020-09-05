CC=gcc
NAME=ft_tail
FTS=ft_tail.c ft_utils.c
OBJ=$(FTS:.c=.o)
FLAGS=-Wall -Wextra -Werror

all:	$(NAME)

$(NAME):
	$(CC) -c $(FLAGS) $(FTS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
