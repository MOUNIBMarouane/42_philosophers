/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 07:22:36 by mamounib          #+#    #+#             */
/*   Updated: 2023/09/14 23:58:17 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_msg(char *msg, t_philo *philo, int unlock)
{
	long long	time;

	sem_wait(philo->info->msg);
	time = get_time() - philo->info->start_time;
	printf("%lld %d %s\n", time, philo->id_philo, msg);
	if (unlock)
		sem_post(philo->info->msg);
}

void	ft_eat(t_philo *philo, sem_t *forks)
{
	sem_wait(forks);
	ft_msg("has taken a fork", philo, 1);
	if (philo->info->nbr_philo == 1)
		ft_sleep(philo->info->time_to_eat, philo);
	sem_wait(forks);
	ft_msg("has taken a fork", philo, 1);
	ft_msg("is eating", philo, 1);
	ft_sleep(philo->info->time_to_eat, philo);
	philo->last_eat = get_time();
	sem_post(forks);
	sem_post(forks);
	philo->times_eat++;
}

void	ft_sleeping(t_philo *philo)
{
	ft_msg("is sleeping", philo, 1);
	ft_sleep(philo->info->time_to_sleep, philo);
}

void	ft_think(t_philo *philo)
{
	ft_msg("is thinking", philo, 1);
}

void	ft_routine(t_philo *philo, sem_t *forks)
{
	int	nmust_eat;

	philo->last_eat = get_time();
	if (philo->id_philo % 2 == 0)
		ft_sleep(1, philo);
	nmust_eat = philo->info->times_must_eat;
	while (1)
	{
		if (philo->times_eat == nmust_eat)
			exit(0);
		ft_eat(philo, forks);
		ft_sleeping(philo);
		ft_think(philo);
	}
}
