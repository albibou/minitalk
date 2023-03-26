/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:40:18 by atardif           #+#    #+#             */
/*   Updated: 2022/11/19 17:23:50 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*swp;
	int		i;

	swp = lst;
	i = 0;
	if (!swp)
		return (0);
	while (swp -> next != NULL)
	{
		swp = swp -> next;
		i++;
	}
	i++;
	return (i);
}
