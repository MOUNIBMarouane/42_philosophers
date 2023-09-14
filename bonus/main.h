/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:21:20 by mamounib          #+#    #+#             */
/*   Updated: 2023/09/14 02:13:59 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_info
{
	sem_t			*msg;
	long long		start_time;
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	int				philo_done;
	sem_t			*mphilo_done;
}	t_info;

typedef struct s_philo	t_philo;

struct s_philo
{
	int				id_philo;
	int				id_proc;
	long long		last_eat;
	sem_t			*mlast_eat;
	int				times_eat;
	t_info			*info;
	t_philo			*next;
};

int			ft_atoi(const char	*str);
long long	get_time(void);
void		ft_sleep(int time, t_philo *philo);

t_info		*ft_init_info(int argc, char **argv);
t_philo		*ft_init_philos(int nbr, t_info *info);
void	ft_msg(char *msg, t_philo *philo, int unlock);

void		ft_start(t_philo *philo, t_info *info, sem_t *forks);
void		ft_routine(t_philo *philo, sem_t *forks);
void		get_philos(t_philo *philos);
void		ft_kill(t_philo *philos);
#endif