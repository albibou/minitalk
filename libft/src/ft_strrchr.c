/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:12:24 by atardif           #+#    #+#             */
/*   Updated: 2022/11/28 09:20:22 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	cop;
	size_t	i;

	if (!s)
		return (NULL);
	str = (char *)s;
	cop = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (str[i] == cop)
			return (str + i);
		i--;
	}
	if (str[i] == cop)
		return (str + i);
	return (NULL);
}
