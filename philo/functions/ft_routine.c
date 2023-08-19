/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:52:42 by mamounib          #+#    #+#             */
/*   Updated: 2023/08/14 16:28:43 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include <pthread.h>
#include <stdio.h>

//time to eat
//time to die
// esting 
// sleeping
// thinking 
// times eating
// and check the death 
// 1 us
// 1 ms 
// usleep(time(ms) * 1000)
// sleep 

/**
 * @brief eat routine
 * 
 * @param philo 
 * 1 - locked his fock and print
 * 2 - locked next forck and print 
 * 3 - sleep time eat
 * 4 - init last meal 
 * 5 - 2 unlock
 */
// void	ft_eat(t_philo *philo)
// {
// 	pthread_mutex_init(&philo->info->msg, NULL);
// 	pthread_mutex_lock(philo->info);
// 	printf("philo :%d take a fork");
// 	printf("philo :%d take a fork");
// 	printf("philo :%d is eating");
// }

// void	ft_routine(t_philo *philo)
// {
// 	while (1)
// 	{
// 		ft_eat(philo);
// 	}
	
// }