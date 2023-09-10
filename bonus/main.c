/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:21:10 by mamounib          #+#    #+#             */
/*   Updated: 2023/09/10 10:40:51 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_info	*info;
	t_philo	*philos;

	if (argc == 5 || argc == 6)
	{
		info = ft_init_info(argc, argv);
		if (!info)
		{
			printf("error: value invalide:");
			return (0);
		}
		philos = ft_init_philos(info->nbr_philo, info);
		ft_start(philos, info);
		get_philos(philos);
	}
	else
		printf("error: syntax error: too many or less arguments");
	return (0);
}
