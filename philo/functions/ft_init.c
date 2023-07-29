/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:49:31 by mamounib          #+#    #+#             */
/*   Updated: 2023/07/29 15:23:07 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief initialize the philosophers
 * 
 */

#include "../main.h"

t_philo	*ft_new_philo()
{
	t_philo	*philo;
	
	philo = (t_philo *)malloc(sizeof(t_philo *));
	// pthread_mutex_init(&philo->fork, NULL);
	philo->next = NULL;
	return (philo);
}

t_philo	*ft_init_philos(int nbr)
{
	t_philo	*first;
	t_philo	*current;
	int		i;

	first  = NULL;
	i = nbr;
	while (i)
	{
		puts("philo");
		if( i == nbr)
		{
			current = ft_new_philo();
			first = current;
			// pthread_mutex_init(&current->fork, NULL);
		}
		else
		{
			current->next = ft_new_philo();
			current = current->next;
			// pthread_mutex_init(&current->fork, NULL);	
		}
		i--;
	}
	current->next = first;
	return (first);
}