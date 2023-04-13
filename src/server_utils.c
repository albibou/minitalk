/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:28:07 by atardif           #+#    #+#             */
/*   Updated: 2023/04/13 15:28:14 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	free_exit(char **buffer, char **line, int client_pid)
{
	free(*line);
	*line = NULL;
	free(*buffer);
	*buffer = NULL;
	if (kill(client_pid, SIGUSR2) < 0)
		exit(1);
	exit(1);
}
