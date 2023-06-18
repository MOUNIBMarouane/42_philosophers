/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:52:42 by mamounib          #+#    #+#             */
/*   Updated: 2023/06/12 08:05:18 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include <pthread.h>
#include <stdio.h>

//time to eat
//time to die
// esting 
// sleeping
// thinking 
// times eating
// and check the death 
// 1 us
// 1 ms 
// usleep(time(ms) * 1000)
// sleep 
long	ft_get_time(struct timeval time)
{

	return ((time.tv_sec / 1000) + (time.tv_usec * 1000));
}

void	ft_eat(t_philo *philo)
{
	long	time;
	struct	timeval	date;
	int x = 1;

	time = ft_get_time(date);
	pthread_mutex_lock(&philo->next->fork);
	pthread_mutex_lock(&philo->fork);
		printf("%ld %d has taken a fork", time, philo->n_philo);
		printf("%ld %d has taken a fork", time, philo->n_philo);
	
	printf("%ld %d is eating", time, philo->n_philo);
}

void	ft_sleep(t_philo *philo)
{
	long	time;

	time = 0;
	printf("%ld %d is sleeping", time, philo->n_philo);
}

void	ft_think(t_philo *philo)
{
	long	time;

	time = 0;
	printf("%ld %d is thinking", time, philo->n_philo);
}

void	ft_routine(t_philo *philo, char **argv)
{
	ft_eat(philo);
	ft_sleep(philo);
	ft_think(philo);
}
