/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:21:10 by mamounib          #+#    #+#             */
/*   Updated: 2023/09/14 03:41:11 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_info	*info;
	t_philo	*philos;
	sem_t	*forks;

	if (argc == 5 || argc == 6)
	{
		info = ft_init_info(argc, argv);
		if (!info)
		{
			printf("error: value invalide:");
			return (0);
		}
		philos = ft_init_philos(info->nbr_philo, info);
		sem_unlink("forks");
		forks = sem_open("forks", O_CREAT, 0644, info->nbr_philo);
		ft_start(philos, info, forks);
	}
	else
		printf("error: syntax error: too many or less arguments");
	ft_kill(philos);
	return (0);
}
