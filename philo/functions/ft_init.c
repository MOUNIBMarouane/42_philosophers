/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:13:39 by mamounib          #+#    #+#             */
/*   Updated: 2023/09/10 02:36:34 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_philo	*ft_new_philo(int id, t_info *info)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	philo->id_philo = id;
	philo->times_eat = 0;
	philo->info = info;
	philo->next = NULL;
	pthread_mutex_init(&philo->fork, NULL);
	pthread_mutex_init(&philo->mlast_eat, NULL);
	return (philo);
}

t_philo	*ft_init_philos(int nbr, t_info *info)
{
	t_philo	*first;
	t_philo	*current;
	int		i;

	first = NULL;
	i = 0;
	while (i++ < nbr)
	{
		if (i == 1)
		{
			first = ft_new_philo(i, info);
			current = first;
		}
		else
		{
			current->next = ft_new_philo(i, info);
			current = current->next;
		}
	}
	current->next = first;
	return (first);
}

void	ft_free_philos(t_philo	*philos)
{
	t_philo	*philo;
	t_philo	*current;

	philo = philos;
	current = philo;
	pthread_mutex_lock(&philo->info->mphilo_done);
	pthread_mutex_destroy(&philo->info->mphilo_done);
	pthread_mutex_destroy(&philo->info->msg);
	free(philos->info);
	while (philo)
	{
		pthread_mutex_lock(&current->fork);
		pthread_mutex_destroy(&current->fork);
		pthread_mutex_lock(&current->mlast_eat);
		pthread_mutex_destroy(&current->mlast_eat);
		philo = philo->next;
		free(current);
		current = philo;
	}
}

long long	init_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000); 
}
