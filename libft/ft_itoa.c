/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:44:11 by atardif           #+#    #+#             */
/*   Updated: 2022/11/21 12:24:29 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_getlen(long n, int count)
{
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static	void	ft_fillstr(char *str, long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
		n = -n;
	}
	else if (n == 0)
	{
		str[i] = '0';
		i++;
	}
	while (n > 0)
	{
		str[i] = ((n % 10) + 48);
		n = n / 10;
		i ++;
	}
	str[i] = '\0';
}

static void	ft_reversestr(char *str, int size, long n)
{
	char	swp;
	int		i;
	int		y;

	i = 0;
	y = 1;
	if (n < 0)
		i = 1;
	while (i < (size - y) && n != 0)
	{
		swp = str[i];
		str[i] = str[size - y];
		str[size - y] = swp;
		i++;
		y++;
	}
}

char	*ft_itoa(int n)
{
	int		count;
	char	*str;
	long	cp;

	cp = (long) n;
	count = 0;
	count = ft_getlen(cp, count);
	if (cp < 0)
		count ++;
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (0);
	ft_fillstr(str, cp);
	ft_reversestr(str, count, cp);
	return (str);
}
