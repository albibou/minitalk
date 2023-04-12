/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:40:23 by atardif           #+#    #+#             */
/*   Updated: 2023/04/11 16:48:07 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_client_pid;

char	*fill_line(char *buffer, char *line)
{
	char	*temp;

	if (!line && buffer[0] != 0)
	{
		line = malloc(sizeof(char));
		line[0] = 0;
	}
	temp = ft_strjoinmod2(line, buffer);
	free(line);
	return (temp);
}

void	handle_string(char c)
{
	static char	*buffer;
	static char	*line;
	static int	i = 0;
	static int	join = 0;

	if (i == 0)
		buffer = malloc(sizeof(char) * 8192);
	if (!buffer)
		return ;
	buffer[i] = c;
	if (i == 8190 && c != '\0')
	{
		buffer[i + 1] = '\0';
		line = fill_line(buffer, line);
		i = 0;
		join++;
	}
	i++;
	if (c == '\0')
	{
		if (join > 0)
		{
			write(1 , line, ft_strlen(line));
			free(line);
			line = NULL;
			i = 0;
			join = 0;
		}
		if (join == 0)
		{
			write(1, buffer, ft_strlen(buffer));
			free(buffer);
			buffer = NULL;
			i = 0;
		}
	}
}

void	handle_sig(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	c = 0;
	static int				i = 7;
	int						mask;

	(void)ucontext;
	mask = 1;
	/*if ( info->si_pid != g_client_pid)
	g_client_pid = info->si_pid;*/
	if (i >= 0)
	{
		if (sig == SIGUSR1)
			c = c | (mask << i);
		i--;
	}
	if (i < 0)
	{
		handle_string(c);
		//write(1, &c, 1);
		i = 7;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("P.I.D  = %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_sig;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
