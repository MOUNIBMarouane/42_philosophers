/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:10:28 by mamounib          #+#    #+#             */
/*   Updated: 2023/07/27 10:56:47 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief check if the number of argc is 5 or 6 then pace the arguments
 * 		  in the parece we need to check if all is a digits
 * 		  then check if the number of arguments is greater than 0
 *		  then set the values info
 * 
 * @param argc 
 * @param argv 
 * @param info 
 */
#include "../main.h"

static int	is_degit(char *arg)
{
	int i;
	
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
	int parce;

	parce = 0;
	if (argc == 5 || argc == 6)
	{
		if (is_degit(argv[1]) && is_degit(argv[2]) && is_degit(argv[3]) && is_degit(argv[4]))
			parce = 1;
		if (argc == 6 && !is_degit(argv[5]))
            parce = 0;
	}
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
	
	info = (t_info *)malloc(sizeof(t_info *));
	if (!info)
		return (NULL);
	if(ft_parce(argc, argv))
	{
		info->nbr_philo = atoi(argv[1]);
		info->time_to_die = atoi(argv[2]);
		info->time_to_eat = atoi(argv[3]);
		info->time_to_sleep = atoi(argv[4]);
		if (argc == 6)
			info->times_must_eat = atoi(argv[5]);
		else
			info->times_must_eat = -1;
		if (ft_check_info(*info, argc))
			return (info);
	}
	return (NULL);
}
