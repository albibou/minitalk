/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:17:12 by atardif           #+#    #+#             */
/*   Updated: 2023/04/13 15:24:12 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
