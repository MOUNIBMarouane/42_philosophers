/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 09:44:05 by mamounib          #+#    #+#             */
/*   Updated: 2022/10/31 23:36:22 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lstn;

	if (lst && del)
	{
		while (*lst)
		{
			lstn = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = lstn;
		}
		free(*lst);
		*lst = NULL;
	}
}
