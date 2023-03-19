/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:43:08 by atardif           #+#    #+#             */
/*   Updated: 2023/03/17 11:09:18 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, int pid)
{
	int	i;
	unsigned char tmp;

	i = 7;
	tmp = 0;
	



void	send_string(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(str[i], pid);
		i++;
	}
}


int	main(int argc, char **argv)
{
	(void)argc;
	
	if (argc == 3)
	{ 
		send_string(argv[2], ft_atoi(argv[1]);

	}
	else
		ft_printf("Usage : ./client [P.I.D. server] [string to send]");

	return (0);
}
