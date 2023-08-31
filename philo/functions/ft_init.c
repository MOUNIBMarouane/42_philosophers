/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: original <original@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:49:31 by mamounib          #+#    #+#             */
/*   Updated: 2023/08/31 10:40:50 by original         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief initialize the philosophers
 * 
 */

#include "../main.h"

t_philo	*ft_new_philo(int id, t_info *info)
{
	t_philo	*philo;
	
	philo = (t_philo *)malloc(sizeof(t_philo));
	philo->id_philo = id;
	philo->info = info;
	philo->next = NULL;
	return (philo);
}

t_philo	*ft_init_philos(int nbr, t_info *info)
{
	t_philo	*first;
	t_philo	*current;
	int		i;

	first  = NULL;
	i = 0;
	while (i++ < nbr)
	{
		if( i == 1)
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
long long	init_time(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000); 
}

void ft_start(t_philo *philo, t_info *info)
{
	int	i;

	i = info->nbr_philo;
	info->start_time = init_time();
	pthread_mutex_init(&info->msg, NULL);
	while (i-- >= 1)
	{
		pthread_create(&philo->thread, NULL, ft_routine, philo);
		pthread_detach(philo->thread);
		philo = philo->next;
	}
}
