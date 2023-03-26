/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:44:30 by atardif           #+#    #+#             */
/*   Updated: 2022/11/21 12:28:15 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	unsigned char	cop;
	size_t			i;

	ps = (unsigned char *)s;
	cop = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ps[i] == cop)
			return (ps + i);
		i++;
	}
	return (0);
}
