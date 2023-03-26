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

int	markup_test;

/*char	build_char(int sig, int i)
{
	static char	c = 0;
	int	mask;

	mask = 1;
	
*/

	


void	handle_sig(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	c;
	static int	i;
	int		mask;

	(void)ucontext;
	if (markup_test == 0)
	{
		c = 0;
		i = 7;
		markup_test = 1;
	}
	mask = 1;
	if (i >= 0)
	{
		if (sig == SIGUSR1)
			c = c | (mask << i);
		usleep(10);
		kill(info->si_pid, SIGUSR1);
		i--;
	}
	if (i < 0)
	{
		write(1, &c, 1);
		markup_test = 0;
		kill(info->si_pid, SIGUSR1);
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
