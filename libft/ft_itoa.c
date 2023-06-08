/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 00:47:18 by mamounib          #+#    #+#             */
/*   Updated: 2022/10/30 15:12:34 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_toalloc(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1 ;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	sing;
	char	*s;
	int		len;

	len = ft_toalloc(n);
	s = (char *)malloc(len + 1);
	if (!s)
		return (0);
	sing = n;
	if (n < 0)
		s[0] = '-';
	else if (n == 0)
			s[0] = '0';
	s[len] = 0;
	if (sing < 0)
		sing *= -1;
	while (sing > 0)
	{
		s[--len] = sing % 10 + '0';
		sing /= 10;
	}
	return (s);
}
