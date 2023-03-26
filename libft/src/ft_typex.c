/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:14:24 by atardif           #+#    #+#             */
/*   Updated: 2022/12/09 14:22:08 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexnumlen(unsigned long int num)
{
	int	len;

	len = 0;
	while ((num / 16) != 0)
	{
		num = num / 16;
		len++;
	}
	len++;
	return (len);
}

void	ft_puthexunbr(unsigned long int num)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (num < 16)
		ft_putchar(base[num]);
	else
	{
		ft_puthexunbr(num / 16);
		ft_puthexunbr(num % 16);
	}
}

void	ft_puthexlnbr(unsigned long int num)
{
	char	*base;

	base = "0123456789abcdef";
	if (num < 16)
		ft_putchar(base[num]);
	else
	{
		ft_puthexlnbr(num / 16);
		ft_puthexlnbr(num % 16);
	}
}

int	ft_ishexl(va_list ap)
{
	unsigned long int	num;
	int					nlen;

	num = (unsigned long int) va_arg(ap, unsigned int);
	ft_puthexlnbr(num);
	nlen = ft_hexnumlen(num);
	return (nlen);
}

int	ft_ishexu(va_list ap)
{
	unsigned long int	num;
	int					nlen;

	num = (unsigned long int) va_arg(ap, unsigned int);
	ft_puthexunbr(num);
	nlen = ft_hexnumlen(num);
	return (nlen);
}
