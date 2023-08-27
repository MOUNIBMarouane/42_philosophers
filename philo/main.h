/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:45:50 by mamounib          #+#    #+#             */
/*   Updated: 2023/08/26 13:57:30 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <time.h>

typedef struct s_info
{
	pthread_mutex_t	msg;
	long long 	 	start_time;
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
}	t_info;

typedef struct s_philo	t_philo;

struct s_philo
{
	pthread_mutex_t	fork;
	pthread_t		thread;
	int				id_philo;
	long long		last_eat;
	int				times_eat;
	t_info			*info;
	t_philo			*next;
};

t_philo	*ft_init_philos(int nbr, t_info *info);
void	ft_add_philo(t_philo *philos, t_philo *philo);
t_info	*ft_init_info(int argc, char **argv);
long long	init_time(void);
int	ft_parce(int argc, char **argv);
long long	get_time(void);
void ft_start(t_philo *philo, t_info *info);
void *ft_routine(void *philo);

void	get_info(t_info info);
void	get_philos(t_philo *philos);

#endif
