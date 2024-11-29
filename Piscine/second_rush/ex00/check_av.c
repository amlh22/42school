#include "puzzle.h"

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	define_n(int l, int *n)
{
	if (l == 31)
		*n = 4;
	else if (l == 39)
		*n = 5;
	else if (l == 47)
		*n = 6;
	else if (l == 55)
		*n = 7;
	else if (l == 63)
		*n = 8;
	else if (l == 71)
		*n = 9;
	else
		return ;
}

int	check_av(char *str, t_puzzle *puzzle)
{
	int	i;
	int	l;

	l = ft_len(str);
	if (l != 31 && l != 39 && l != 47 && l != 55 && l != 63 && l != 71)
		return (0);
	define_n(l, &puzzle->n);
	i = 0;
	while (str[i])
	{
		if (i % 2 == 0 && !(str[i] >= '1' && str[i] <= ('0' + puzzle->n)))
			return (0);
		else if (i % 2 == 1 && str[i] != ' ' )
			return (0);
		i++;
	}
	return (1);
}
