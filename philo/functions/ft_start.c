/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 02:35:37 by mamounib          #+#    #+#             */
/*   Updated: 2023/09/15 00:18:21 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_death_checker(t_philo *philo, t_info *info, int nbr_philo)
{
	long long	sum;

	while (1)
	{
		while (philo)
		{
			pthread_mutex_lock(&info->mphilo_done);
			if (info->philo_done == info->nbr_philo)
				return ;
			pthread_mutex_unlock(&info->mphilo_done);
			pthread_mutex_lock(&philo->mlast_eat);
			sum = (get_time() - philo->last_eat);
			pthread_mutex_unlock(&philo->mlast_eat);
			if (sum > info->time_to_die)
			{
				ft_msg("is dead", philo, 0);
				return ;
			}
			philo = philo->next;
			if (philo->id_philo == nbr_philo)
				break ;
		}
		usleep(1000);
	}
}

void	ft_start(t_philo *philo, t_info *info)
{
	int			i;

	i = info->nbr_philo;
	pthread_mutex_init(&info->msg, NULL);
	info->start_time = get_time();
	while (i-- >= 1)
	{
		philo->last_eat = get_time();
		pthread_create(&philo->thread, NULL, ft_routine, philo);
		philo = philo->next;
	}
	i = info->nbr_philo;
	while (i-- >= 1)
	{
		pthread_detach(philo->thread);
		philo = philo->next;
	}
	ft_death_checker(philo, info, info->nbr_philo);
}
