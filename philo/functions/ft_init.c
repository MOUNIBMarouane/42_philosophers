/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: killwa <killwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:13:39 by mamounib          #+#    #+#             */
/*   Updated: 2023/07/20 13:15:43 by killwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include <pthread.h>

t_philo	*ft_new_philo(t_info info)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->next = NULL;
	pthread_mutex_init(&philo->fork, NULL);
	return (philo);
}

void	init_info(char **argv, t_info *info)
{
	info->time_to_die = atoi(argv[2]);
	info->time_to_eat = atoi(argv[3]);
	info->time_to_sleep = atoi(argv[4]);
	pthread_mutex_init(&info->msg, NULL);	
}

t_philo	*ft_init_philos(t_philo *philos,t_info info, int nbr)
{
	t_philo	*first;
	t_philo *current;

	first = NULL;
	while (nbr--)
	{
		current = ft_new_philo(info);
		if (first == NULL)
			first = current;
		else
		{
			current->next = ft_new_philo(info);
			current = current->next;
		}
		current->next = first;
	}
	philos = first;
	return (philos);
}
long long	ft_get_time(void)
{
	struct timeval tv;
	long long	time;
	
	gettimeofday(^tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}