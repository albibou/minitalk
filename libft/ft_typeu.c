/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typeu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:03:06 by atardif           #+#    #+#             */
/*   Updated: 2022/12/09 14:21:43 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsnumlen(unsigned long int num)
{
	int	len;

	len = 0;
	while ((num / 10) != 0)
	{
		num = num / 10;
		len ++;
	}
	len++;
	return (len);
}

void	ft_putunsnbr(unsigned long int num)
{
	if (num <= 9)
		ft_putchar(num + '0');
	else
	{
		ft_putunsnbr(num / 10);
		ft_putunsnbr(num % 10);
	}
}

int	ft_isuns(va_list ap)
{
	unsigned long int	num;
	int					nlen;

	num = (unsigned long int) va_arg(ap, unsigned int);
	ft_putunsnbr(num);
	nlen = ft_unsnumlen(num);
	return (nlen);
}
