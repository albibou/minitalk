/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:16:12 by atardif           #+#    #+#             */
/*   Updated: 2022/11/21 12:35:48 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	else if (len == 0)
		return (NULL);
	else
	{
		while (big [i] && i < len)
		{
			y = 0;
			while ((big[i + y] == little[y]) && big[i + y] && i + y < len)
				y++;
			if (little[y] == '\0')
				return ((char *)big + i);
			i++;
		}
	}
	return (NULL);
}
