/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:55:02 by atardif           #+#    #+#             */
/*   Updated: 2022/11/21 12:28:59 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*cd;
	unsigned char	*cs;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	cd = (unsigned char *)dest;
	cs = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		cd[i] = cs[i];
		i++;
	}
	return (dest);
}
