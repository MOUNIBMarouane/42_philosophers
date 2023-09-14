/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:56:09 by mamounib          #+#    #+#             */
/*   Updated: 2023/09/14 03:23:02 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_kill(t_philo *philos)
{
	t_philo	*tmp;
	int		i;

	if (!philos)
		return ;
	tmp = philos;
	i = 0;
	while (i++ != tmp->info->nbr_philo)
	{
		kill(tmp->id_proc, 0);
		tmp = tmp->next;
	}
	exit(1);
}
