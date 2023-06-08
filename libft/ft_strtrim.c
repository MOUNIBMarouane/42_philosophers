/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:25:49 by mamounib          #+#    #+#             */
/*   Updated: 2022/11/01 17:14:22 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_in(char *s1, char c)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	end;
	char	*p;

	p = NULL;
	if (!s1 || !set)
		return (0);
	j = ft_strlen(s1);
	if (j)
		end = j - 1;
	i = 0;
	while (s1[i] && is_in((char *)set, s1[i]))
		i++;
	while (s1[i] && is_in((char *)set, s1[end]) && i < end)
		end--;
	p = ft_substr(s1, i, end - i + 1);
	return (p);
}
