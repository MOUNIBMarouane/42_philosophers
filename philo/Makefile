
NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread
RM = rm -f

FILES= philo/main.c \
	   philo/functions/ft_routine.c \
	   philo/functions/ft_parce.c \
	   philo/functions/ft_init.c \
	   philo/help.c

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