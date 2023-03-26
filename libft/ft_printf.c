/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:13:31 by atardif           #+#    #+#             */
/*   Updated: 2023/01/10 13:11:27 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strchrmod(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (c);
		i++;
	}
	if (str[i] == c)
		return (c);
	return (-1);
}

static int	ft_convcall(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_ischar(ap);
	else if (c == 's')
		count += ft_isstr(ap);
	else if (c == 'i' || c == 'd')
		count += ft_isint(ap);
	else if (c == 'u')
		count += ft_isuns(ap);
	else if (c == 'x')
		count += ft_ishexl(ap);
	else if (c == 'X')
		count += ft_ishexu(ap);
	else if (c == 'p')
		count += ft_ispoint(ap);
	else
	{
		write (1, "%", 1);
		count++;
	}
	return (count);
}

static int	ft_formatparsing(const char *format, int count, va_list ap)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (ft_strchrmod(format[i + 1], "cspdiuxX%"))
			{
				i++;
				count += ft_convcall(format[i], ap);
			}
		}
		else
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	count = ft_formatparsing(format, count, ap);
	va_end(ap);
	return (count);
}
