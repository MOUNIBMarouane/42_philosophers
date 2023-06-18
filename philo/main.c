/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:43:16 by mamounib          #+#    #+#             */
/*   Updated: 2023/06/10 15:20:35 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdlib.h>


int	main(int argc, char **argv)
{
	t_philo philos;
	t_info	info;
	
	ft_init_info(argv, &info);
	if (argc == 6)
		info.times_eat = atoi(argv[5]);
	ft_init_philos(&philos, info, atoi(argv[1]));
	return (0);
}
