/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typedi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:31:01 by atardif           #+#    #+#             */
/*   Updated: 2022/12/08 14:49:19 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(int num)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while ((num / 10) != 0)
	{
		num = num / 10;
		len++;
	}
	len++;
	return (len);
}

void	ft_putnbr(long int num)
{
	if (num < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-num);
	}
	else if (num >= 0 && num <= 9)
		ft_putchar(num + '0');
	else
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
}

int	ft_isint(va_list ap)
{
	long int	num;
	int			nlen;

	num = (long) va_arg(ap, int);
	ft_putnbr(num);
	nlen = ft_numlen(num);
	return (nlen);
}
