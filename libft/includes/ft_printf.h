/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:48:25 by atardif           #+#    #+#             */
/*   Updated: 2023/01/10 13:29:51 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_ischar(va_list ap);
int		ft_isint(va_list ap);
int		ft_numlen(int num);
int		ft_ispoint(va_list ap);
int		ft_putstr(char *str);
int		ft_isstr(va_list ap);
int		ft_unsnumlen(unsigned long int num);
int		ft_isuns(va_list ap);
int		ft_hexnumlen(unsigned long int num);
int		ft_ishexl(va_list ap);
int		ft_ishexu(va_list ap);
void	ft_putchar(char c);
void	ft_putnbr(long int num);
void	ft_putunsnbr(unsigned long int num);
void	ft_puthexunbr(unsigned long int num);
void	ft_puthexlnbr(unsigned long int num);

#endif
