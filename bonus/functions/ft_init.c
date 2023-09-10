/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 03:32:38 by mamounib          #+#    #+#             */
/*   Updated: 2023/09/10 03:47:58 by mamounib         ###   ########.fr       */
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
	free(philos->info);
	while (philo)
	{
		philo = philo->next;
		free(current);
		current = philo;
	}
}
