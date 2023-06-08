/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 09:24:50 by mamounib          #+#    #+#             */
/*   Updated: 2022/10/31 23:45:46 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	while (ft_isdigit(str[i]) && str[i])
	{
		nombre = (nombre * 10) + (str[i] - 48);
		i++;
	}
	return (nombre * sing);
}
