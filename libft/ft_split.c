/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:59:58 by atardif           #+#    #+#             */
/*   Updated: 2023/01/31 17:10:10 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_wordnbr(char *str, char c)
{
	int	i;
	int	wdnb;

	wdnb = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			wdnb++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (wdnb);
}

static int	ft_wordlen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	*ft_putword(char *str, char c, char **tab)
{
	char	*word;
	int		i;
	int		wordlen;

	i = 0;
	wordlen = ft_wordlen(str, c);
	word = malloc(sizeof(char) * (wordlen + 1));
	if (!word)
	{
		ft_freetab(tab);
		return (NULL);
	}
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab_word;
	int		wdnb;
	int		i;
	char	*str;

	str = (char *)s;
	wdnb = ft_wordnbr(str, c);
	tab_word = malloc(sizeof(char *) * (wdnb + 1));
	if (!tab_word)
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && *str == c)
			str++;
		if (*str != '\0')
		{
			tab_word[i] = ft_putword(str, c, tab_word);
			i++;
		}
		while (*str != '\0' && *str != c)
			str++;
	}
	tab_word[i] = 0;
	return (tab_word);
}
