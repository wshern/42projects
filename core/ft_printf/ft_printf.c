/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 18:08:32 by werlim            #+#    #+#             */
/*   Updated: 2026/09/01 17:58:13 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

static int f_ident(const char type, va_list list)
{
	if (type == 'c')
	else if (type == 's')
	else if (type == 'p')
	else if (type == 'd' || type == 'i')
	else if (type == 'u')
	else if (type == 'x' || type == 'X')
	else if (type == '%')
		return (ft_putchar('%'));
}

int ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;
	int		charcount;

	i = 0;
	charcount = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			
		}
		else if (s[i] == '%' && s[i + 1] == '\0')
			return (-1);
		else
		{
			ft_putchar_fd(s[i], 1);
			charcount++;
		}
		i++;
	}
	va_end(list);
	return (charcount);
}