/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 09:50:46 by mamounib          #+#    #+#             */
/*   Updated: 2023/09/10 02:39:15 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	is_degit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_parce(int argc, char **argv)
{
	int	parce;

	parce = 0;
	if (is_degit(argv[1]) && is_degit(argv[2]) && \
	is_degit(argv[3]) && is_degit(argv[4]))
		parce = 1;
	if (argc == 6 && !is_degit(argv[5]))
		parce = 0;
	return (parce);
}

int	ft_check_info(t_info info, int argc)
{
	int	checker;

	checker = 1;
	if (info.nbr_philo <= 0 || info.time_to_die <= 0 \
	|| info.time_to_eat <= 0 || info .time_to_sleep <= 0)
		checker = 0;
	if (argc == 6 && info.times_must_eat <= 0)
		checker = 0;
	return (checker);
}

t_info	*ft_init_info(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	if (ft_parce(argc, argv))
	{
		pthread_mutex_init(&info->mphilo_done, NULL);
		info->philo_done = 0;
		info->nbr_philo = ft_atoi(argv[1]);
		info->time_to_die = ft_atoi(argv[2]);
		info->time_to_eat = ft_atoi(argv[3]);
		info->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			info->times_must_eat = ft_atoi(argv[5]);
		else
			info->times_must_eat = -1;
		if (ft_check_info(*info, argc))
			return (info);
	}
	free(info);
	return (NULL);
}
