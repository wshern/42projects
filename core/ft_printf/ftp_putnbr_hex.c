/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putnbr_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 20:34:18 by werlim            #+#    #+#             */
/*   Updated: 2026/09/02 21:45:38 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftp_putnbr_hex(long nbr)
{
	char	result;
	int		counter;

	counter = 0;
	if (nbr < 0)
	{
		counter += ftp_putchar('-');
		nbr = -nbr;
	}
	if (nbr / 16 == 0)
	{
		result = nbr + '0';
		counter += ftp_putchar(result);
	}
	else
	{
		counter += ftp_putnbr_hex(nbr / 10);
		counter += ftp_putnbr_hex(nbr % 10);
	}
	return (counter);
}
