# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 17:53:45 by rdedola           #+#    #+#              #
#    Updated: 2024/09/30 17:53:45 by rdedola          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE			=	philosophers

# Files
SRC			=	./main.c \
				./src/init.c \
				./src/routine.c \
				./src/monitor_check.c \

SRC_UTILS	=	./src/utils/ft_atoi.c \
				./src/utils/ft_puterr_ex.c \
				./src/utils/ft_puterr_re.c \
				./src/utils/get_time.c \
				./src/utils/ft_usdie.c \
				./src/utils/ft_leave.c \
				./src/utils/take_fork.c \

SOURCES		=	${SRC} ${SRC_UTILS}
OBJECTS		=	${SOURCES:%.c=obj/%.o}

# Variables
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf

# Makefile
all:		${EXE}

${EXE}:		${OBJECTS}
			@${CC} ${CFLAGS} ${OBJECTS} -o ${EXE}

obj/%.o:	%.c
			@mkdir -p obj/$(dir $<)
			@${CC} ${CFLAGS} -c $< -o $@

clean:
			@${RM} obj
			@${RM} #{EXE}.log

fclean:		clean
			@${RM} ${EXE}

re:			fclean all

.PHONY:		all clean fclean re
