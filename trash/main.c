/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:42:48 by atardif           #+#    #+#             */
/*   Updated: 2023/03/19 21:14:51 by atardif          ###   ########.fr       */
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

void	test_bitwise(void)
{
	char	c;
	int	ref;
	int	i;
	int	mask;

	c = 0;
	ref = 0;
	i = 0;
	mask = 1;
	while (i < 8)
	{
		scanf("%d", &ref);
		if (ref == 1)
			c = c | mask;
		else if (ref == 0)
			c = c & mask;
		display_binary_bis(c);
		c = c << 1;
		i++;
	}

}


int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	/*
	int	i;

	i = 0;
	while (argv[1][i])
	{
		display_binary(argv[1][i]);
		i++;
	}*/

	test_bitwise();
	/*printf("Size of char : %ld\n", sizeof(char));
	printf("Size of unsigned char : %ld\n", sizeof(unsigned char));
	printf("Size of int : %ld\n", sizeof(int));
	printf("Size of unsigned int : %ld\n", sizeof(unsigned int));
	printf("Size of long : %ld\n", sizeof(long));
	printf("Size of unsigned long : %ld\n", sizeof(unsigned long));
	printf("Size of long long : %ld\n", sizeof(long long));*/
	return(0);
}
