/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:45:50 by mamounib          #+#    #+#             */
/*   Updated: 2023/06/06 23:11:55 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <pthread.h>
# include <stdlib.h>


typedef struct s_info
{
	int	nbr_fork;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_think;
	int	time_to_die;
	int	times_eat;
}	t_info;

typedef struct s_philo	t_philo;

struct s_philo
{
	int		n_philo;
	t_info	info;
	t_philo	*first;
	t_philo	*last;
	t_philo	*next;
};

#endif
