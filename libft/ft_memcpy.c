/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:58:56 by mamounib          #+#    #+#             */
/*   Updated: 2022/11/01 00:01:39 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dist, const void *src, size_t n)
{
	size_t	i;

	if (dist == src)
		return (dist);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dist)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dist);
}
