/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:27:05 by atardif           #+#    #+#             */
/*   Updated: 2023/04/09 17:27:07 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile size_t	g_can_send;

void	handle_sig(int sig)
{
	static int	bit_received = 0;

	if (sig == SIGUSR1)
	{
		bit_received++;
		g_can_send += bit_received;
	}
}

void	send_char(char c, int pid)
{
	int					i;
	int					mask;
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_handler = &handle_sig;
	sigaction(SIGUSR1, &sa, NULL);
	i = 7;
	mask = 1;
	while (i >= 0)
	{
		g_can_send = 0;
		if (c & (mask << i))
		{
			if (kill(pid, SIGUSR1) < 0)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) < 0)
				exit(1);
		}
		while (g_can_send == 0)
			pause();
		i--;
	}
}

void	send_string(char *str, int pid)
{
	int	i;
	int	end;

	i = 0;
	end = ft_strlen(str);
	g_can_send = 1;
	while (i <= end)
	{
		send_char(str[i], pid);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		send_string(argv[2], ft_atoi(argv[1]));
		if (g_can_send == (ft_strlen(argv[2]) + 1) * 8)
			ft_printf("Chars sent : %d , String received\n", (g_can_send / 8) - 1);
	}
	else
		ft_printf("Usage : ./client [P.I.D. server] [string to send]");
	return (0);
}
