#include "puzzle.h"

int	is_doubles(t_puzzle *puzzle, int i, int pos);
int	check_up_col(t_puzzle *puzzle, int i, int pos);
int	check_down_col(t_puzzle *puzzle, int i, int pos);
int	check_right_row(t_puzzle *puzzle, int i, int pos);
int	check_left_row(t_puzzle *puzzle, int i, int pos);

int	is_valid(t_puzzle *puzzle, int i, int pos)
{
	if (!(is_doubles(puzzle, i, pos)))
		return (0);
	if (!(check_up_col(puzzle, i, pos)))
		return (0);
	if (!(check_down_col(puzzle, i, pos)))
		return (0);
	if (!(check_right_row(puzzle, i, pos)))
		return (0);
	if (!(check_left_row(puzzle, i, pos)))
		return (0);
	return (1);
}

int	solve_puzzle(t_puzzle *puzzle, int pos)
{
	int	i;
	int	t;

	t = puzzle->n;
	if (pos == t * t)
		return (1);
	else
	{
		i = 1;
		while (i <= puzzle->n)
		{
			if (is_valid(puzzle, i, pos))
			{
				puzzle->board[pos / puzzle->n][pos % puzzle->n] = i;
				if (solve_puzzle(puzzle, pos + 1))
					return (1);
			}
			puzzle->board[pos / puzzle->n][pos % puzzle->n] = 0;
			i++;
		}
	}
	return (0);
}
