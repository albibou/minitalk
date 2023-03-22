/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:42:48 by atardif           #+#    #+#             */
/*   Updated: 2023/03/22 15:35:51 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


void	display_binary(char c)
{
	int	i;

	i = 0;
	printf("%c : ", c);
	while (i < 8)
	{
		printf("%d", !!((c << i) & 0x80));
		i++;
	}
	printf("\n");
}

void	display_binary_bis(char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		printf("%d", !!((c << i) & 0x80));
		i++;
	}
	printf("\n");
}

int	sendchar(char c)
{
	int	mask;

	mask = 1;
	mask = mask & c;
	if (mask == 1)
		return (1);
	else
		return (0);
}

void	test_bitwise(char s)
{
	unsigned char	c;
	int	i;
	unsigned int	mask;

	c = 0;
	i = 0;
	mask = 1;
	while (i < 7)
	{
		if (sendchar(s) == 1)
			c = c | mask;
		c = c << 1;
		s = s >> 1;
		i++;
	}
	mask = 0;
	while (i >= 0)
	{
		mask = mask << 1;
		if (c & 1 == 1)
			mask = mask ^ 1;
		c = c >> 1;
		i--;
	}
	//display_binary(mask);
	printf("%c", mask);

}


int	main(int argc, char **argv)
{
	(void)argc;
	int	i;

	i = 0;
	while (argv[1][i])
	{
		test_bitwise(argv[1][i]);
		i++;
	}
	printf("\n");
	return(0);
}
