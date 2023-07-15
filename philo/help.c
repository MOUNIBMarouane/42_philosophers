/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: killwa <killwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:18:21 by mamounib          #+#    #+#             */
/*   Updated: 2023/07/09 13:18:29 by killwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

void	get_info(t_info info)
{
	puts("philo info");
	printf("nombr philo            : %d \n",info.nbr_philo);
	printf("philo tmie to die      : %d \n",info.time_to_die);
	printf("philo time to eat      : %d \n",info.time_to_eat);
	printf("philo time to sleep    : %d \n",info.time_to_sleep);
	printf("philo time must to eat : %d \n",info.time_to_sleep);
}
