# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/15 17:18:19 by ttranche          #+#    #+#              #
#    Updated: 2020/08/15 17:31:06 by ttranche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		=		./srcs/
HEAD_DIR	=		./includes/
SRCS		= 		${SRC_DIR}ft_putchar.c\
					${SRC_DIR}ft_swap.c\
					${SRC_DIR}ft_putstr.c\
					${SRC_DIR}ft_strlen.c\
					${SRC_DIR}ft_strcmp.c
HEAD		=		${HEAD_DIR}ft.h
OBJS		= ${SRCS:.c=.o}
NAME		= libft.a
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -I${HEAD_DIR} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar -rc libft.a ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
