/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:20:12 by atardif           #+#    #+#             */
/*   Updated: 2022/12/04 16:03:35 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	cop;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	cop = (char)c;
	while (str[i])
	{
		if (str[i] == cop)
			return (str + i);
		i++;
	}
	if (str[i] == cop)
		return (str + i);
	return (NULL);
}
