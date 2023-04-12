/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:27:13 by atardif           #+#    #+#             */
/*   Updated: 2023/04/12 18:13:25 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strjoinmod(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[y])
	{
		dest[i + y] = s2[y];
		y++;
	}
	dest[i + y] = 0;
	return (dest);
}

char	*fill_line(char *buffer, char *line)
{
	char	*temp;

	if (!line && buffer[0] != 0)
	{
		line = malloc(sizeof(char));
		line[0] = 0;
	}
	temp = ft_strjoinmod(line, buffer );
	free(line);
	return (temp);
}

void	print_line(char *buffer, char *line, int i, int join)
{
	if (join > 0)
	{
		write(1 , line, ft_strlen(line));
		i = 0;
		join = 0;
	}
	if (join == 0)
	{
		write(1, buffer, ft_strlen(buffer));
		i = 0;
	}
}

void	handle_string(char c)
{
	static char	*buffer;
	static char	*line;
	static int	i = 0;
	static int	join = 0;

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
	{
		print_line(buffer, line, i, join);
		i = 0;
		join = 0;
		free(line);
		free(buffer);
		/*if (join > 0)
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
		}*/
	}
}

void	handle_sig(int sig, siginfo_t *info, void *ucontext)
{
	static char	c = 0;
	static int				i = 7;
	static int						mask = 1;

	(void)ucontext;
	if (sig == SIGUSR1)
		c = c | (mask << i);
	i--;
	if (i < 0)
	{
		handle_string(c);
		i = 7;
		c = 0;
	}
	if (kill(info->si_pid, SIGUSR1) < 0)
		exit(1);
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
