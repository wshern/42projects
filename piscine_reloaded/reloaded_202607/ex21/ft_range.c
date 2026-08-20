/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 16:25:49 by werlim            #+#    #+#             */
/*   Updated: 2026/07/26 16:59:44 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	srclength;
	int	i;

	i = 0;
	srclength = max - min;
	if (min >= max)
		return (NULL);
	arr = (int *) malloc(sizeof(int) * srclength);
	if (arr == NULL)
		return (NULL);
	while (min < max)
		arr[i++] = min++;
	return (arr);
}

/*
int ft_atoi(char *str)
{
	int	i;
	int	nve;
	int	nbr;

	i = 0;
	nve = 0;
	nbr = 0;
	while (str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			nve++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (nve == 1)
		nbr = -nbr;
	return (nbr);
}

#include <stdio.h>
int	main(int ac, char **av)
{
	int	i;
	int	min;
	int	max;
	int	*arr;

	if (ac != 3)
	{
		printf("need argument for min and max");
		return (0);
	}
	min = ft_atoi(av[1]);
	max = ft_atoi(av[2]);
	arr = ft_range(min, max);
	if (arr == NULL)
	{
		printf("NULL");
		return (0);
	}
	i = 0;
	printf("result: ");
	while (i < max - min)
		printf("%d", arr[i++]);
	printf("\n");
	free(arr);
	return (0);
}*/
