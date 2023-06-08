/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:02:56 by mamounib          #+#    #+#             */
/*   Updated: 2022/10/18 17:02:51 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ih;
	size_t	in;

	if ((!haystack && !len) || needle[0] == '\0' )
		return ((char *)haystack);
	ih = 0;
	while (haystack[ih])
	{
		in = 0;
		while (needle[in] && in + ih < len && needle[in] == haystack[ih + in])
			in++;
		if (!needle[in])
			return ((char *)haystack + ih);
		ih++;
	}
	return (0);
}
