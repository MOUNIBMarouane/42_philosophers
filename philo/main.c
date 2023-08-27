/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:43:16 by mamounib          #+#    #+#             */
/*   Updated: 2023/08/26 14:01:47 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	lk(){
	system("leaks philo");
}

int main(int argc, char **argv)
{
	t_info *info;
	t_philo	*philos;

	if (argc == 5 || argc == 6)
	{
		info = ft_init_info(argc, argv);
		if (!info)
		{
			printf("error: value invalide:");
			return 0;
		}
		philos = ft_init_philos(info->nbr_philo, info);
		pthread_mutex_init(&info->msg, NULL);
		ft_start(philos, info);
	}
	else
		printf("error: syntax error: too many or less arguments");
	return 0;
}
