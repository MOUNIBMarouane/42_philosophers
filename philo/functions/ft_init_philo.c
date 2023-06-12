/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:13:39 by mamounib          #+#    #+#             */
/*   Updated: 2023/06/12 07:52:15 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include <pthread.h>
#include <sys/_pthread/_pthread_mutex_t.h>

t_philo	*ft_new_philo(t_info info)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->next = NULL;
	philo->info = &info;
	pthread_mutex_init(&philo->fork, NULL);
	return (philo);
}

void	ft_add_philo(t_philo *philos, t_philo *philo)
{
	if (!philos->n_philo)
		philos->first = philo;
	else
		philos->last->next = philo;
	philo->next = philos->first;
	philos->last = philo;
	philos->n_philo ++;
}

void	init_info(char **argv, t_info *info)
{
	info->time_to_die = atoi(argv[2]);
	info->time_to_eat = atoi(argv[3]);
	info->time_to_sleep = atoi(argv[4]);
}

t_philo	*ft_init_philos(t_philo *philos,t_info info,int nbr)
{
	t_philo	*philo;

	while (nbr)
	{
		philo = ft_new_philo(info);
		ft_add_philo(philos, philo);
		free(philo);
		nbr --;
	}
	return (philos);
}
