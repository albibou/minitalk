/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:43:08 by atardif           #+#    #+#             */
/*   Updated: 2023/03/14 17:43:42 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"



int	main(int argc, char **argv)
{
	(void)argc;
	
	if (argc == 3)
	{

		kill(ft_atoi(argv[1]), SIGINT);
	}
	else
		ft_printf("Ecris avec deux arguments");

	return (0);
}
