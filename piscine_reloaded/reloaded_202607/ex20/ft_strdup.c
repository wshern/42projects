/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 15:44:21 by werlim            #+#    #+#             */
/*   Updated: 2026/07/26 22:42:12 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		strlength;
	char	*dest;

	i = 0;
	strlength = str_len(src);
	dest = (char *) malloc(sizeof(char) * (strlength + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>
int	main(int ac, char **av)
{
	char	*result;

	if (ac == 2)
	{
		result = ft_strdup(av[1]);
		printf("duplicate: %s\n", result);
		free(result);
		return (0);
	}
	else
		printf("2 Arguments Only");
	return (0);
}*/
