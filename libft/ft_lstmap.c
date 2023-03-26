/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:11:09 by atardif           #+#    #+#             */
/*   Updated: 2022/11/20 14:22:26 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_list;
	t_list	*begin;

	if (!lst || !f)
		return (NULL);
	n_list = ft_lstnew((*f)(lst -> content));
	begin = n_list;
	lst = lst -> next;
	while (lst)
	{
		n_list = ft_lstnew((*f)(lst -> content));
		if (!n_list)
			ft_lstclear(&begin, (*del));
		ft_lstadd_back(&begin, n_list);
		lst = lst -> next;
	}
	return (begin);
}
