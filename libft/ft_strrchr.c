/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:28:14 by mamounib          #+#    #+#             */
/*   Updated: 2022/10/31 02:13:32 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (((unsigned char *)s)[len] == (unsigned char)c)
			return ((char *)s + len);
		len--;
	}
	return (0);
}
