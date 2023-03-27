/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:40:23 by atardif           #+#    #+#             */
/*   Updated: 2023/03/24 17:40:57 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	fill_string(char c)
{
	static char	str[4096];
	static int	i = 0;

	str[i] = c;
	i++;
	if (c == '\0')
	{
		write (1, str, ft_strlen(str));
		i = 0;
	}
}
	
void	handle_sig(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	c = 0;
	static int	i = 7;
	int		mask;

	(void)ucontext;
	mask = 1;
	if (i >= 0)
	{
		if (sig == SIGUSR1)
			c = c | (mask << i);
		//usleep(10);
		if (i > 0)
			kill(info->si_pid, SIGUSR1);
		i--;
	}
	if (i < 0)
	{
		//write(1, &c, 1);
		fill_string(c);
		i = 7;
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	struct sigaction	sa;

	ft_printf("P.I.D  = %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_sig;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
