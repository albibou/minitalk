/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:43:08 by atardif           #+#    #+#             */
/*   Updated: 2023/03/23 13:39:56 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	can_send;

void	send_char(char c, int pid)
{
	int	i;
	int	mask;

	i = 0;
	while (i < 7)
	{
		mask = 1;
		mask = mask & c;
		if (mask == 1)
			kill(pid, SIGUSR1);
		else 
			kill(pid, SIGUSR2);
		c = c >> 1;
		i++;
		usleep(1000);
	}
}

void	send_string(char *str, int pid)
{
	int	i;
	//struct sigaction	sa;

	i = 0;
	can_send = 1;
	while (str[i])
	{
		send_char(str[i], pid);
		i++;
	}
}


int	main(int argc, char **argv)
{
	(void)argc;;
	
	if (argc == 3)
	{ 
		send_string(argv[2], ft_atoi(argv[1]));
	}
	else
		ft_printf("Usage : ./client [P.I.D. server] [string to send]");

	return (0);
}
