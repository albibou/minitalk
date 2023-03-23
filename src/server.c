/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:40:23 by atardif           #+#    #+#             */
/*   Updated: 2023/03/23 13:39:19 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	markup_test;

void	handle_sig(int sig)
{
	static unsigned char	c;
	static int	i;
	int		mask;

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
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	struct sigaction	sa;

	markup_test = 0;
	//sa = malloc(sizeof(struct sigaction) * 1);
	ft_printf("P.I.D  = %d\n", getpid());
	sa.sa_flags = 0;
	sa.sa_handler = &handle_sig;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
