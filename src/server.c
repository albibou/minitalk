/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:40:23 by atardif           #+#    #+#             */
/*   Updated: 2023/04/07 17:43:10 by atardif          ###   ########.fr       */
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
	temp = ft_strjoinmod(line, buffer);
	free(buffer);
	free(line);
	return (temp);
}

/*void	handle_string(char c)
{
	char	*buffer;
	static char	*line;
	static int	i;

	buffer = malloc(sizeof(char) * (2));
	if (!buffer)
		return ;
	buffer[0] = c;
	buffer[1] = '\0';
	if (c == '\0')
	{
		write(1, line, ft_strlen(line));
		i = 0;
		//free(line);
		return ;
	}
	line = fill_line(buffer, line);
	free(buffer);
}*/

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
	i++;
	if (i == 4094 && c != '\0')
	{
		buffer[++i] = '\0';
		line = fill_line(buffer, line);
		i = 0;
		join++;
	}
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

/*void	fill_string(char c)
{
	static char	str[50000];
	static int	i = 0;

	str[i] = c;
	i++;
	if (c == '\0')
	{
		write (1, str, ft_strlen(str));
		i = 0;
	}
}*/

void	handle_sig(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	c = 0;
	static int				i = 7;
	int						mask;

	(void)ucontext;
	mask = 1;
	if (i >= 0)
	{
		if (sig == SIGUSR1)
			c = c | (mask << i);
		if (i > 0)
			kill(info->si_pid, SIGUSR1);
		i--;
	}
	if (i < 0)
	{
		handle_string(c);
		i = 7;
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
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
