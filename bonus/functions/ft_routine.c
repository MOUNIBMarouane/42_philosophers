/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 07:22:36 by mamounib          #+#    #+#             */
/*   Updated: 2023/09/10 07:34:04 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_msg(char *msg,t_philo *philo, int unlock)
{
	long long	time;

	time = get_time() - philo->info->start_time;
	printf("%lld %d %s \n", time, philo->id_philo, msg);
}

void	ft_eat(t_philo *philo)
{
	ft_msg("has taken a fork", philo, 1);
	ft_msg("has taken a fork", philo, 1);
	ft_msg("is eating", philo, 1);
	ft_sleep(philo->info->time_to_eat);
	philo->last_eat = get_time();
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

void	ft_routine(t_philo *philo)
{
	while (1)
	{
		ft_eat(philo);
		ft_sleeping(philo);
		ft_think(philo);
	}
}