# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thsembel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/24 18:21:06 by thsembel          #+#    #+#              #
#    Updated: 2020/08/26 14:59:01 by ttranche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 		./bsq.c ./main.c ./map_reader.c

HEAD		=		./bsq.h ./map_reader.h

OBJS		= ${SRCS:.c=.o}

NAME		= BSQ

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror
.c.o:
					${CC} ${CFLAGS} -I"${HEAD}" -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
					${CC} ${CFLAGS} -o ${NAME} ${OBJS}


all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all	clean	fclean re
