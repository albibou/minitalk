/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:43:15 by atardif           #+#    #+#             */
/*   Updated: 2022/12/09 14:20:04 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ispoint(va_list ap)
{
	unsigned long int	num;
	int					len;

	len = 0;
	num = (unsigned long int) va_arg(ap, void *);
	if (num == 0)
	{
		write(1, "(nil)", 5);
		len += 5;
	}
	else
	{
		write(1, "0x", 2);
		ft_puthexlnbr(num);
		len = ft_hexnumlen(num) + 2;
	}
	return (len);
}
