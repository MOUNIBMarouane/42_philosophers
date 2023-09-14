/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:45:50 by mamounib          #+#    #+#             */
/*   Updated: 2023/09/10 03:35:47 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>

typedef struct s_info
{
	pthread_mutex_t	msg;
	long long		start_time;
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	int				philo_done;
	pthread_mutex_t	mphilo_done;
}	t_info;

typedef struct s_philo	t_philo;

struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	fork;
	int				id_philo;
	long long		last_eat;
	pthread_mutex_t	mlast_eat;
	int				times_eat;
	t_info			*info;
	t_philo			*next;
};

t_philo		*ft_init_philos(int nbr, t_info *info);
void		ft_add_philo(t_philo *philos, t_philo *philo);
t_info		*ft_init_info(int argc, char **argv);
int			ft_parce(int argc, char **argv);
long long	get_time(void);
void		ft_start(t_philo *philo, t_info *info);
void		*ft_routine(void *philo);
void		ft_sleep(int time);
void		get_info(t_info info);
void		get_philos(t_philo *philos);
void		ft_msg(char *msg, t_philo *philo, int unlock);
int			ft_atoi(const char	*str);

#endif