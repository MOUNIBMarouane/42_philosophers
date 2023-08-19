/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:43:16 by mamounib          #+#    #+#             */
/*   Updated: 2023/08/14 16:26:13 by mamounib         ###   ########.fr       */
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
		get_info(*info);
		philos = ft_init_philos(info->nbr_philo, info);
		get_philos(philos);
		ft_start(philos, info);
	}
	else
		printf("error: syntax error: too many or less arguments");
	return 0;
}
