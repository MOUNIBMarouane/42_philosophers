/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: killwa <killwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:45:50 by mamounib          #+#    #+#             */
/*   Updated: 2023/07/09 13:19:50 by killwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
typedef struct s_info
{
	pthread_mutex_t	msg;
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
int main(int argc, char **argv);
void	get_info(t_info info);
#endif
