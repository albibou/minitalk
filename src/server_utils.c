/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:46:07 by atardif           #+#    #+#             */
/*   Updated: 2023/04/09 19:50:44 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


