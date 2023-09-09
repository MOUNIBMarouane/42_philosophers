/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:52:42 by mamounib          #+#    #+#             */
/*   Updated: 2023/09/08 15:27:04 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_msg(char *msg, t_philo *philo, int unlock)
{
	long long	time;
	int			times;

	pthread_mutex_lock(&philo->info->msg);
	time = init_time() - philo->info->start_time;
	printf("%lld %d %s ", time, philo->id_philo, msg);
	times = philo->info->times_must_eat;
	// if (times >= 0)
	// 	printf("%d ", philo->info->times_must_eat);
	printf("\n");
	if (unlock)
		pthread_mutex_unlock(&philo->info->msg);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	ft_msg("has taken a fork", philo, 1);
	pthread_mutex_lock(&philo->next->fork);
	ft_msg("has taken a fork", philo, 1);
	ft_msg("is eating", philo, 1);
	ft_sleep(philo->info->time_to_eat);
	pthread_mutex_lock(&philo->mlast_eat);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->mlast_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
	philo->times_eat++;
}

void	ft_sleeping(t_philo *philo)
{
	ft_msg("is sleeping", philo, 1);
	ft_sleep(philo->info->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	ft_msg("is thinking", philo, 1);
}

void	*ft_routine(void *philo)
{
	t_philo	*phil;
	int		nmust_eat;

	phil = (t_philo *) philo;
	pthread_mutex_lock(&phil->mlast_eat);
	phil->last_eat = get_time();
	pthread_mutex_unlock(&phil->mlast_eat);
	if (phil->id_philo == 1)
		phil->info->start_time = get_time();
	if (phil->id_philo % 2 == 0)
		usleep(400);
	nmust_eat = phil->info->times_must_eat;
	while (1)
	{
		if (phil->times_eat == nmust_eat)
			break;
		ft_eat(phil);
		ft_sleeping(phil);
		ft_think(phil);
	}
	pthread_mutex_lock(&phil->info->mphilo_done);
	phil->info->philo_done++;
	pthread_mutex_unlock(&phil->info->mphilo_done);
	return (NULL);
}
