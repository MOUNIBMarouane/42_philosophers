
NAME = philo

CC = cc -g
CFLAGS = -Wall -Wextra -Werror 

FILES= main.c \
	   functions/ft_routine.c \
	   functions/ft_parce.c \
	   functions/ft_init.c \
	   functions/ft_utils.c \
	   functions/ft_start.c \

OBJECT = ${FILES:.c=.o}

all : ${NAME}

${NAME} : ${OBJECT}
	${CC} ${CFLAGS} ${OBJECT} -o $@

%.o : %.c philo/main.h
	${CC} ${CFLAGS} -c -o $@ $<

clean :
	$(RM) $(OBJECT)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : fclean clean re all