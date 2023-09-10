/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:21:20 by mamounib          #+#    #+#             */
/*   Updated: 2023/09/10 10:32:58 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <sys/time.h>

typedef struct s_info
{
	long long		start_time;
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	int				philo_done;
}	t_info;

typedef struct s_philo	t_philo;

struct s_philo
{
	int				id_philo;
	int				id_proc;
	long long		last_eat;
	int				times_eat;
	t_info			*info;
	t_philo			*next;
};

int			ft_atoi(const char	*str);
long long	get_time(void);
void		ft_sleep(int time);

t_info		*ft_init_info(int argc, char **argv);
t_philo		*ft_init_philos(int nbr, t_info *info);
void		ft_routine(t_philo *philo);

void		ft_start(t_philo *philo, t_info *info);


void	get_philos(t_philo *philos);
#endif