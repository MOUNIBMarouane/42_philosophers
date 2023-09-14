/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 07:34:52 by mamounib          #+#    #+#             */
/*   Updated: 2023/09/14 03:22:04 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_start(t_philo *philo, t_info *info, sem_t *forks)
{
	int		i;
	int		status;
	t_philo	*tmp;

	i = 0;
	tmp = philo;
	sem_unlink("msg");
	info->msg = sem_open("msg", O_CREAT, 0644, 1);
	info->start_time = get_time();
	while (i++ < info->nbr_philo)
	{
		tmp->id_proc = fork();
		if (tmp->id_proc == 0)
			ft_routine(tmp, forks);
		tmp = tmp->next;
	}
	waitpid(-1, &status, 0);
	if (status)
		ft_kill(philo);
	i = 0 ;
	while (i++ < info->nbr_philo)
	{
		waitpid(tmp->id_proc, NULL, 0);
		tmp = tmp->next;
	}
}
