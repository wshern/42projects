#include <stdlib.h>
#include <stdio.h>

// refer to libft for correct itoa
// refer to libft for correct itoa
// refer to libft for correct itoa

int	numlen(int nbr)
{
	int	i;

	i = 0;
	while (nbr / 10 != 0)
	{
		if (nbr % 10 != 0)
			i++;
		nbr /= 10;
	}
	if (nbr / 10 == 0)
		i++;
	return (i);
}

char *ft_itoa(int nbr)
{
	int		numlength;
	int		isnve;
	int		i;
	char	*ptr;

	numlength = numlen(nbr);
	isnve = 0;
	if (nbr < 0)
		isnve = 1;
	ptr = (char *) malloc(sizeof (char) * numlength + 1 + isnve);
	if (ptr == NULL)
		return (NULL);
	//printf("malloc: %d\n", numlength + 1 + isnve);
	if (nbr < 0)
	{
		ptr[0] = '-';
		nbr = -nbr;
	}
	//printf("%c\n", ptr[0]);
	i = numlength + isnve;
	ptr[i] = '\0';
	i--;
	while (nbr / 10 != 0)
	{
		ptr[i] = (nbr % 10) + '0';
		i--;
		nbr /= 10;
	}
	//printf("%s\n", ptr);
	if (nbr / 10 == 0)
		ptr[i] = nbr % 10 + '0';
	return (ptr);
}
/*
int	main(void)
{
	char *c;
	int	n = -1932;

	c = ft_itoa(n);
	printf("%c\n", c[0]);
	printf("result: %s\n", c);
	free(c);
	return (0);
}
*/