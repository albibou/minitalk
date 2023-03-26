/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:35:19 by atardif           #+#    #+#             */
/*   Updated: 2022/11/21 12:37:26 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	size_t			i;
	size_t			y;

	i = 0;
	y = 0;
	if (len > ft_strlen(s)- 1 - start)
		len = (ft_strlen(s) - start);
	else if (start > ft_strlen(s) -1)
		len = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		if (i >= start && y < len)
		{
			dest[y] = s[i];
			y++;
		}
		i++;
	}
	dest[y] = 0;
	return (dest);
}
