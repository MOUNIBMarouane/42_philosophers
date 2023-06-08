/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:02:41 by mamounib          #+#    #+#             */
/*   Updated: 2022/10/16 15:57:55 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;	
	size_t	lensrc;
	size_t	lendst;

	if (!dst && !dstsize)
		return (ft_strlen(src));
	lendst = ft_strlen(dst);
	lensrc = ft_strlen (src);
	i = 0;
	if (!dstsize || lendst > dstsize)
		return (lensrc + dstsize);
	while (src[i] && (lendst + i < dstsize - 1))
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = 0;
	return (lendst + lensrc);
}
