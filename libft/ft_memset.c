/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:59:40 by atardif           #+#    #+#             */
/*   Updated: 2022/11/28 09:24:26 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dst;
	unsigned char	cop;
	size_t			i;

	dst = (unsigned char *)s;
	cop = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dst[i] = cop;
		i++;
	}
	return (s);
}
