/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:40:23 by atardif           #+#    #+#             */
/*   Updated: 2023/03/24 17:12:12 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	markup_test;

void	handle_sig(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	c;
	static int	i;
	int		mask;
	int		c_pid;

	(void)ucontext;
	c_pid = (int)info->si_pid;
	if (markup_test == 0)
	{
		c = 0;
		i = 0;
		markup_test = 1;
	}
	mask = 1;
	if (i < 7)
	{
		if (sig == SIGUSR1)
			c = c | mask;
		c = c << 1;
		usleep(10);
		if (i < 6)
			kill(c_pid, SIGUSR1);
		i++;
	}
	if (i >= 7)
	{
		mask = 0;
		while (i >= 0)
		{
			mask = mask << 1;
			if (c & 1)
				mask = mask ^ 1;
			c = c >> 1;
			i--;
		}
		ft_printf("%c", mask);
		if (i == 0)
			ft_printf("\n");
		markup_test = 0;
		kill(c_pid, SIGUSR1);
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	struct sigaction	sa;

	markup_test = 0;
	ft_printf("P.I.D  = %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_sig;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
