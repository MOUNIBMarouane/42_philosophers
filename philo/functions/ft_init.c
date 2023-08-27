/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:49:31 by mamounib          #+#    #+#             */
/*   Updated: 2023/08/26 16:24:34 by mamounib         ###   ########.fr       */
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
// void	ft_addback(t_philo **philo, t_philo *node)
// {
	
// }

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
		printf("philo %d\n", current->id_philo);
	}
	printf("philo %d\n", current->id_philo);
	
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

	t_philo *first;
	first = philo;
	i = info->nbr_philo;
	info->start_time = init_time();
	pthread_mutex_init(&info->msg, NULL);
	info->start_time = init_time();
	while (i-- >= 1)
	{
		pthread_mutex_init(&philo->fork, NULL);
		philo = philo->next;
	}
	philo = first;
	i = info->nbr_philo;
	while (i-- >= 1)
	{
		if (philo->id_philo % 2 == 0)
		usleep(50);
		// pthread_mutex_init(&philo->fork);
		pthread_create(&philo->thread, NULL, ft_routine, philo);
		pthread_detach(philo->thread);
		usleep(50);
		philo = philo->next;
	}
}
