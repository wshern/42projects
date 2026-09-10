/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 18:23:41 by werlim            #+#    #+#             */
/*   Updated: 2026/09/10 16:23:24 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(const char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (i);
	return (-1);
}

char	*gnl_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*dest;

	dest = malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	j = 0;
	if (s1)
	{
		i = 0;
		while (s1[i])
			dest[j++] = s1[i++];
	}
	if (s2)
	{
		i = 0;
		while (s2[i])
			dest[j++] = s2[i++];
	}
	dest[j] = '\0';
	return (dest);
}

int	gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strcpy(const char *s, int start, int end, char *dest)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (start <= end)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
