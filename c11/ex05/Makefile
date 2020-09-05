
CC=gcc
NAME=do-op
FTS=do_op.c
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
