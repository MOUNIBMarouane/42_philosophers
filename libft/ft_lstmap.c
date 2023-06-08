/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:56:04 by mamounib          #+#    #+#             */
/*   Updated: 2022/10/31 23:32:29 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstn;
	t_list	*lstp;

	lstp = NULL;
	while (lst)
	{
		lstn = ft_lstnew(f(lst->content));
		if (!lstn)
			ft_lstclear(&lstp, del);
		ft_lstadd_back(&lstp, lstn);
		lst = lst->next;
	}
	return (lstp);
}
