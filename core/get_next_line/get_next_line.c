/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:17:49 by werlim            #+#    #+#             */
/*   Updated: 2026/09/09 18:55:55 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_nextline(int fd, char *stash)
{
	char	*rd_buf;
	int		rd_n;

	rd_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!rd_buf)
		return (0);
	while (find_newline(stash) == -1)
	{
		rd_n = read(fd, rd_buf, BUFFER_SIZE);
		if (rd_n == -1)
		{
			free(rd_n);
			return (NULL);
		}
		else if (rd_n == 0)
			break;
		rd_buf[rd_n] = '\0';
		gnl_strjoin(stash, rd_buf);
	}
	return (gnl_split(stash));
}

char	*get_next_line(int fd)
{
	static char *stash = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_nextline(fd, stash);
	
}