/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 18:20:54 by werlim            #+#    #+#             */
/*   Updated: 2026/09/11 18:17:37 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

char	*get_next_line(int fd);
char	*update_storage(int fd, char *storage);
char	*gnl_strbefore(const char *s, int i);
char	*gnl_strafter(char *s, int i);
char	*gnl_strcpy(const char *s, int start, int end, char *dest);
int		gnl_strlen(const char *s);
char	*gnl_strjoin(const char *s1, const char *s2);
int		find_newline(const char *s);
char	*gnl_free(char *s1, char *s2);

#endif