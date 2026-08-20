/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 22:09:08 by werlim            #+#    #+#             */
/*   Updated: 2026/07/20 22:11:19 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
int	main(void)
{
	int a = 10;
	int b = 7;
	printf("before\n");
	printf("x = %d, y = %d", a, b);
	ft_swap(a, b);
	printf("after\n");
	printf("x = %d, y = %d", a ,b)
	return (0);
}
*/
