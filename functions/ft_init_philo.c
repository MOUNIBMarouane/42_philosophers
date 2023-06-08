/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:13:39 by mamounib          #+#    #+#             */
/*   Updated: 2023/06/07 01:54:43 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../manda/main.h"

t_philo	*ft_new_philo(t_info info)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->next = NULL;
	philo->info = info;
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
