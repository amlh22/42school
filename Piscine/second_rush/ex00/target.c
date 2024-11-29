#include "puzzle.h"

int	target_isvalid(t_puzzle *puzzle)
{
	int	i;
	int	n;
	int	opposite;

	i = 0;
	n = puzzle->n;
	while (i < (n * 4))
	{
		if (puzzle->target[i] == n)
		{
			if (i < n)
				opposite = puzzle->target[i + n];
			else if (i < n * 2)
				opposite = puzzle->target[i - n];
			else if (i < n * 3)
				opposite = puzzle->target[i + n];
			else
				opposite = puzzle->target[i - n];
			if (opposite != 1)
				return (0);
		}
		i++;
	}
	return (1);
}

void	fill_target(t_puzzle *puzzle, char *input)
{
	int	i;
	int	ctr;

	ctr = 0;
	i = 0;
	while (input[i])
	{
		if (i % 2 == 0)
		{
			puzzle->target[ctr] = input[i] - '0';
			ctr++;
		}
		i++;
	}
}
