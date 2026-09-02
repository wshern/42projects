/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 20:34:18 by werlim            #+#    #+#             */
/*   Updated: 2026/09/02 21:40:58 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftp_putnbr_dec(int nbr)
{
	char	result;
	int		counter;

	if (nbr == -2147483648)
		return (ftp_putstr("-2147483648"));
	counter = 0;
	if (nbr < 0)
	{
		counter += ftp_putchar('-');
		nbr = -nbr;
	}
	if (nbr / 10 == 0)
	{
		result = nbr + '0';
		counter += ftp_putchar(result);
	}
	else
	{
		counter += ftp_putnbr_dec(nbr / 10);
		counter += ftp_putnbr_dec(nbr % 10);
	}
	return (counter);
}
