
NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread
RM = rm -f

FILES= philo/main.c \
	   philo/functions/ft_routine.c \
	   philo/functions/ft_parce.c \
	   philo/functions/ft_init.c \
	   philo/help.c
