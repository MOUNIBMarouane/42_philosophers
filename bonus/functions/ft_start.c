/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 07:34:52 by mamounib          #+#    #+#             */
/*   Updated: 2023/09/10 10:42:22 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_start(t_philo *philo, t_info *info)
{
	int		i;
	int		pid;
	t_philo *tmp;

	i = 0;
	tmp = philo;
	pid = fork();
	while (i++ < info->nbr_philo)
	{
		if (pid == 0)
		{
			pid = fork();
			if (pid != 0)
			{
				tmp->id_proc = pid;
			}
		}
		tmp = tmp->next;
	}
}
