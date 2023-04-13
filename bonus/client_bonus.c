/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:27:05 by atardif           #+#    #+#             */
/*   Updated: 2023/04/13 15:26:09 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile size_t	g_can_send;

void	exit_client(int tmp)
{
	if (tmp == 1)
	{
		ft_printf("Wrong PID, try again.\n");
		exit(1);
	}
}

void	handle_sig(int sig, siginfo_t *info, void *ucontext)
{
	static int	bit_received = 0;

	(void)ucontext;
	(void)info;
	if (sig == SIGUSR1)
	{
		bit_received++;
		g_can_send += bit_received;
	}
	else if (sig == SIGUSR2)
	{
		ft_printf("Error server side. Relaunch everything.\n");
		exit(1);
	}
}

void	send_char(char c, int pid)
{
	int			i;
	static int	mask = 1;

	i = 7;
	while (i >= 0)
	{
		g_can_send = 0;
		if (c & (mask << i))
		{
			if (kill(pid, SIGUSR1) < 0)
				exit_client(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) < 0)
				exit_client(1);
		}
		while (g_can_send == 0)
		{
		}
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
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = &handle_sig;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc == 3 && ft_strlen(argv[2]) != 0)
	{
		send_string(argv[2], ft_atoi(argv[1]));
		if (g_can_send == (ft_strlen(argv[2]) + 1) * 8)
			ft_printf("Chars sent : %d , String received\n",
				(g_can_send / 8) - 1);
	}
	else
		ft_printf("Usage : ./client [P.I.D. server] [string to send]");
	return (0);
}
