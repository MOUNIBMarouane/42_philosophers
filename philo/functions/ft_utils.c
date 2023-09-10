/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:55:53 by mamounib          #+#    #+#             */
/*   Updated: 2023/09/10 02:39:41 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	ft_atoi(const char	*str)
{
	int			sing;
	long long	nombre;
	long long	i;

	sing = 1;
	i = 0;
	nombre = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sing = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nombre = (nombre * 10) + (str[i] - 48);
		i++;
	}
	return (nombre * sing);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_sleep(int time)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(500);
}
