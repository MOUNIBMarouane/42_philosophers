/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:18:21 by mamounib          #+#    #+#             */
/*   Updated: 2023/08/05 18:12:23 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

void	get_info(t_info info)
{
	puts("philo info ");
	printf("nombr philo            : %d \n",info.nbr_philo);
	printf("philo tmie to die      : %d \n",info.time_to_die);
	printf("philo time to eat      : %d \n",info.time_to_eat);
	printf("philo time to sleep    : %d \n",info.time_to_sleep);
	printf("philo time must to eat : %d \n",info.times_must_eat);
}

void	get_philos(t_philo *philos)
{
	t_philo	*current;
	// t_philo *next;

	int	i = 0;
	current = philos;
	// printf("philo id %d \n", current->id_philo);
	while (i < current->next->id_philo)
	{
		printf("philo id %d \n", current->id_philo);
		current = current->next;
		i++;
	}
	printf("philo n %d \n", i);
}