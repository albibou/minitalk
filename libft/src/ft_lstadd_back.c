/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:08:19 by atardif           #+#    #+#             */
/*   Updated: 2022/11/19 17:22:32 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*swp;

	swp = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (swp -> next != NULL)
		{
			swp = swp -> next;
		}
		swp -> next = new;
	}
}
