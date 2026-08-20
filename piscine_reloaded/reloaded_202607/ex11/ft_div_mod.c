/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 18:14:10 by werlim            #+#    #+#             */
/*   Updated: 2026/07/21 18:17:51 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
#include <stdio.h>
int	main(void)
{
	int	a = 13;
	int	b = 2;
	int	div;
	int	mod;

	ft_div_mod(a, b, &div, &mod);
	printf("div = %d", div);
	printf("mod = %d", mod);
	return (0);
}*/
