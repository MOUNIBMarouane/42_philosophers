
NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread
RM = rm -f

FILES= philo/main.c \
	   philo/functions/ft_init_philo.c \
	   philo/functions/ft_routine.c
