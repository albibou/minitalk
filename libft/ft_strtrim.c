/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:10:44 by atardif           #+#    #+#             */
/*   Updated: 2022/11/21 12:36:40 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_isinset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_getstart(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		while (s1[i] && ft_isinset(s1[i], set))
			i++;
		if (s1[i] && ft_isinset(s1[i], set) == 0)
			return (i);
	}
	return (0);
}

static int	ft_getend(const char *s1, const char *set)
{
	int	i;

	i = 0;
	i = ft_strlen(s1) - 1;
	while (ft_isinset(s1[i], set))
		i--;
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		destsize;
	int		i;
	int		start;

	destsize = (ft_getend(s1, set) - ft_getstart(s1, set));
	i = 0;
	start = ft_getstart(s1, set);
	dest = malloc(sizeof(char) * (destsize + 1));
	if (!dest)
		return (0);
	while (i < destsize)
	{
		dest[i] = s1[i + start];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
