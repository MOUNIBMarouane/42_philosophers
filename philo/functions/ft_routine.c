/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: original <original@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:52:42 by mamounib          #+#    #+#             */
/*   Updated: 2023/08/31 11:13:26 by original         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include <pthread.h>
#include <stdio.h>

void	ft_msg(char *msg, t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->info->msg);
	time = init_time() - philo->info->start_time;
	printf("%lld %d %s\n", time, philo->id_philo, msg);
	pthread_mutex_unlock(&philo->info->msg);
}
void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	ft_msg("has taken a fork",philo);
	pthread_mutex_lock(&philo->next->fork);
	ft_msg("has taken a fork",philo);
	philo->last_eat = init_time();
	ft_msg("is eating", philo);
	usleep(philo->info->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}
void	ft_sleep(t_philo *philo)
{
	ft_msg("is sleeping", philo);
	usleep(philo->info->time_to_sleep);
}
void	ft_think(t_philo *philo)
{
	ft_msg("is thinking", philo);
}

void *ft_routine(void *philo)
{
	t_philo *phil;
	phil = (t_philo *)philo;
	if (phil->id_philo % 2 == 0)
		usleep(400);
	while (1)
	{
		ft_eat(phil);
		ft_sleep(phil);
		ft_think(phil);
	}
	return ((void *)NULL);
}