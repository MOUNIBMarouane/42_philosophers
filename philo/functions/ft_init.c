/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:13:39 by mamounib          #+#    #+#             */
/*   Updated: 2023/09/09 16:03:01 by mamounib         ###   ########.fr       */
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
	pthread_mutex_init(&philo->fork, NULL);
	pthread_mutex_init(&philo->mlast_eat, NULL);
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
	pthread_mutex_lock(&philo->info->mphilo_done);
	pthread_mutex_destroy(&philo->info->mphilo_done);
	pthread_mutex_destroy(&philo->info->msg);
	free(philos->info);
	while (philo)
	{
		pthread_mutex_lock(&current->fork);
		pthread_mutex_destroy(&current->fork);
		pthread_mutex_lock(&current->mlast_eat);
		pthread_mutex_destroy(&current->mlast_eat);
		philo =  philo->next;
		free(current);
		current = philo;
	}
}

long long	init_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000); 
}

void	ft_start(t_philo *philo, t_info *info)
{
	int	i;
	long long sum;

	i = info->nbr_philo;
	pthread_mutex_init(&info->msg, NULL);
	info->start_time = get_time();
	while (i-- >= 1)
	{
		philo->last_eat = get_time();
		pthread_create(&philo->thread, NULL, ft_routine, philo);
		philo = philo->next;
	}
	i = info->nbr_philo;
	while (i-- >= 1)
	{
		pthread_detach(philo->thread);
		philo = philo->next;
	}
	i = philo->id_philo;
	while (1)
	{
		while (philo)
		{
			pthread_mutex_lock(&info->mphilo_done);
			if (info->philo_done == info->nbr_philo)
				return ;
			pthread_mutex_unlock(&info->mphilo_done);
			pthread_mutex_lock(&philo->mlast_eat);
			sum = (get_time() - philo->last_eat);
			pthread_mutex_unlock(&philo->mlast_eat);
			if (sum > info->time_to_die)
			{
				ft_msg("is dead", philo, 0);
				return ;
			}
			philo = philo->next;
			if (philo->id_philo == i)
				break ;
		}
		usleep(1000);
	}
}
