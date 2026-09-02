/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 18:08:32 by werlim            #+#    #+#             */
/*   Updated: 2026/09/02 21:41:22 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int f_ident(const char type, va_list list)
{
	if (type == 'c')
		return (ftp_putchar(va_arg(list, int)));
	else if (type == 's')
		return (ftp_putstr(va_arg(list, char *)));
	else if (type == 'p')
	else if (type == 'd' || type == 'i')
		return (ftp_putnbr_dec(va_arg(list, int)));
	else if (type == 'u')
	else if (type == 'x' || type == 'X')
	else if (type == '%')
		return (ftp_putchar('%'));
	return (-1);
}

int ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;
	int		charcount;

	if (!s || *s == '\0')
		return (0);
	i = 0;
	charcount = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '\0')
			{
				va_end(list);
				return (-1);
			}
			else
				f_indent(s[++i], list);
		}
		else
		{
			ft_putchar(s[i]);
			charcount++;
		}
		i++;
	}
	va_end(list);
	return (charcount);
}