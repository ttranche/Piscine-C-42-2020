SRCS = dict.c number_process.c utils.c utils2.c verif.c lines.c main.c blocks.c
OBJS = ${SRCS:.c=.o}
NAME = rush-02
CFLAGS = -Wall -Werror -Wextra
CC = cc
RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
	${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re: 		fclean all

.PHONY: all clean fclean re
