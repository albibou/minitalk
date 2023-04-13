/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:27:13 by atardif           #+#    #+#             */
/*   Updated: 2023/04/13 15:24:42 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static char	*fill_line(char *buffer, char *line)
{
	char	*temp;

	if (!line && buffer[0] != 0)
	{
		line = malloc(sizeof(char));
		line[0] = 0;
	}
	temp = ft_strjoinmod(line, buffer);
	free(line);
	return (temp);
}

static void	print_line(char **buffer, char **line, int *i, int *join)
{
	if (*join > 0)
	{
		write(1, *line, ft_strlen(*line));
		free(*line);
		*line = NULL;
		*i = 0;
		*join = 0;
	}
	if (*join == 0)
	{
		write(1, *buffer, ft_strlen(*buffer));
		free(*buffer);
		*buffer = NULL;
		*i = 0;
	}
}

static void	handle_string(char c, int code, int client_pid)
{
	static char	*buffer;
	static char	*line;
	static int	i = 0;
	static int	join = 0;

	if (code == 1)
		free_exit(&buffer, &line, client_pid);
	if (i == 0)
		buffer = malloc(sizeof(char) * 4096);
	if (!buffer)
		return ;
	buffer[i] = c;
	if (i == 4094 && c != '\0')
	{
		buffer[i + 1] = '\0';
		line = fill_line(buffer, line);
		i = 0;
		join++;
	}
	i++;
	if (c == '\0')
		print_line(&buffer, &line, &i, &join);
}

static void	handle_sig(int sig, siginfo_t *info, void *ucontext)
{
	static char	c = 0;
	static int	i = 7;
	int			mask;

	(void)ucontext;
	mask = 1;
	if (sig == SIGUSR1)
		c = c | (mask << i);
	i--;
	if (i < 0)
	{
		handle_string(c, 0, info->si_pid);
		i = 7;
		c = 0;
	}
	if (kill(info->si_pid, SIGUSR1) < 0)
		handle_string(c, 1, info->si_pid);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("P.I.D  = %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = &handle_sig;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
