/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:21:48 by atardif           #+#    #+#             */
/*   Updated: 2022/11/21 12:30:39 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cd;
	unsigned char	*cs;
	int				y;

	cd = (unsigned char *)dest;
	cs = (unsigned char *)src;
	y = (int)n - 1;
	if (cd > cs)
	{
		while (y >= 0)
		{
			cd[y] = cs[y];
			y--;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}	
	return (dest);
}
