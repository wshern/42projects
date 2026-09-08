/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:17:49 by werlim            #+#    #+#             */
/*   Updated: 2026/09/07 21:18:36 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_nextline(int fd)
{
	char	*rd_buf;
	int		rd_n;

	rd_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!rd_buf)
		return (0);
	rd_n = 1;
	if (rd_n == 0)
		return (0);
	while (rd_n > 0)
	{
		rd_n = read(fd, rd_buf, BUFFER_SIZE);
		if (rd_n == -1)
			return ;
		rd_buf[rd_n] = '\0';
		buffer = gnl_strjoin(stash, rd_buf);
		if (gnl_strchr(buffer) == 1)
			break;
	}
	
}

char	*get_next_line(int fd)
{
	static char *stash = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
}