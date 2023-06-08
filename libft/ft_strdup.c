/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:48:11 by mamounib          #+#    #+#             */
/*   Updated: 2022/10/16 15:36:42 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!p)
		return (0);
	else
		ft_strlcpy(p, (char *)s1, ft_strlen(s1) + 1);
	return (p);
}
