/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:49:31 by mamounib          #+#    #+#             */
/*   Updated: 2023/07/25 16:35:52 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief initialize the philosophers
 * 
 */

#include "../main.h"

t_philo	*ft_new_philo(void)
{
	t_philo	*philo;
	
	philo = (t_philo *)malloc(sizeof(t_philo *));
	philo->next = NULL;
	pthread_mutex_init(&philo->fork, NULL);
	return (philo);
}

t_philo	*init_philos(int nbr)
{
	t_philo *current;
	t_philo *first;
	
	while (nbr--)
	{
		current = ft_new_philo();
		if (first == NULL)
			first = current;
		else
		{
			current->next = ft_new_philo();
			current = current->next;
		}
		current->next = first;
	}
	return (first);
}