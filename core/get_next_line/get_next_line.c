/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:17:49 by werlim            #+#    #+#             */
/*   Updated: 2026/09/10 16:29:08 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strbefore(const char *s, int i)
{
	char	*strbefore;

	if (!s)
		return (NULL);
	if (i != -1)
		strbefore = malloc(sizeof(char) * (i + 2));
	else
		strbefore = malloc(sizeof(char) * (gnl_strlen(s) + 1));
	if (!strbefore)
		return (NULL);
	if (i != -1)
		strbefore = gnl_strcpy(s, 0, i, strbefore);
	else
		strbefore = gnl_strcpy(s, 0, (gnl_strlen(s) - 1), strbefore);
	return (strbefore);
}

char	*gnl_strafter(char *s, int i)
{
	char	*strafter;
	int		str_len;

	if (!s)
		return (NULL);
	str_len = gnl_strlen(s);
	if (i == -1 || i + 1 == str_len)
	{
		free(s);
		return (NULL);
	}
	else
		strafter = malloc(sizeof(char) * (str_len - i));
	if (!strafter)
	{
		free(s);
		return (NULL);
	}
	strafter = gnl_strcpy(s, (i + 1), (str_len - 1), strafter);
	free(s);
	return (strafter);
}

char	*update_storage(int fd, char *storage)
{
	char	*rd_buf;
	char	*temp;
	int		rd_n;

	rd_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!rd_buf)
		return (NULL);
	while (find_newline(storage) == -1)
	{
		rd_n = read(fd, rd_buf, BUFFER_SIZE);
		if (rd_n == -1)
		{
			free(rd_buf);
			free(storage);
			return (NULL);
		}
		else if (rd_n == 0)
			break ;
		rd_buf[rd_n] = '\0';
		temp = gnl_strjoin(storage, rd_buf);
		free(storage);
		storage = temp;
	}
	free(rd_buf);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*rtn_str;
	int			newline_i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = update_storage(fd, storage);
	newline_i = find_newline(storage);
	rtn_str = gnl_strbefore(storage, newline_i);
	storage = gnl_strafter(storage, newline_i);
	return (rtn_str);
}
