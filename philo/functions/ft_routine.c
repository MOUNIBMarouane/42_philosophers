/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:52:42 by mamounib          #+#    #+#             */
/*   Updated: 2023/08/26 16:16:18 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include <pthread.h>
#include <stdio.h>

/**
 * @brief eat routine
 * 
 * @param philo 
 * 1 - locked his fock and print
 * 2 - locked next forck and print 
 * 3 - sleep time eat
 * 4 - init last meal 
 * 5 - 2 unlock
 */

void	ft_msg(char *msg, t_philo *philo, int unlock)
{
	long long	time;

	pthread_mutex_lock(&philo->info->msg);
	time = init_time() - philo->info->start_time;
	printf("%lld %d %s\n", time, philo->id_philo, msg);
	if (unlock)
		pthread_mutex_unlock(&philo->info->msg);
}
void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	ft_msg("has taken a fork",philo, 1);
	pthread_mutex_lock(&philo->next->fork);
	ft_msg("has taken a fork",philo, 1);
	philo->last_eat = init_time();
	ft_msg("is eating", philo, 1);
	usleep(philo->info->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
	ft_msg("is sleeping", philo, 1);
	usleep(philo->info->time_to_sleep);
}

void *ft_routine(void *philo)
{
	t_philo *phil;

	phil = (t_philo *)philo;
	while (1)
	{
		ft_eat(phil);
	}
	return ((void *)NULL);
}