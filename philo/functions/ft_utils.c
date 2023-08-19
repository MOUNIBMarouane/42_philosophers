/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:19:59 by mamounib          #+#    #+#             */
/*   Updated: 2023/07/29 18:10:21 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../main.h"
// int	ft_atoi(char *nbr)
// {
	
// }
long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv,NULL);
	return(tv.tv_sec * 1000 + tv.tv_usec / 1000);
}