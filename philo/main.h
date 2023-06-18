/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:45:50 by mamounib          #+#    #+#             */
/*   Updated: 2023/06/11 15:58:58 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <pthread.h>
# include <stdlib.h>
# include <sys/_pthread/_pthread_t.h>
# include <sys/time.h>
# include <stdio.h>
typedef struct s_info
{
	pthread_mutex_t	msg;
	int				nbr_fork;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
}	t_info;

typedef struct s_philo	t_philo;

struct s_philo
{
	pthread_mutex_t	fork;
	int				n_philo;
	pthread_t		thread;
	long			last_eat;
	int				times_eat;
	t_philo			*first;
	t_info			*info;
	t_philo			*last;
	t_philo			*next;
};

t_philo	*ft_init_philos(t_philo *philos,t_info info,int nbr);
void	ft_add_philo(t_philo *philos, t_philo *philo);
t_philo	*ft_new_philo(t_info info);
void	ft_init_info(char **argv, t_info *info);

#endif
