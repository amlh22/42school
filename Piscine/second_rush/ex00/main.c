#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "puzzle.h"

int		check_av(char *str, t_puzzle *puzzle);
void	fill_target(t_puzzle *puzzle, char *input);
int		target_isvalid(t_puzzle *puzzle);
int		solve_puzzle(t_puzzle *puzzle, int pos);

void	print_error(int type)
{
	if (type == 1)
		write(1, &"INPUT FORMAT INCORRECT", 23);
	else if (type == 2)
		write(1, &"NO SOLUTION", 12);
}

void	display_solution(t_puzzle *puzzle)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	while (i < puzzle->n)
	{
		j = 0;
		while (j < puzzle->n)
		{
			temp = puzzle->board[i][j] + 48;
			write(1, &temp, 1);
			if (j % puzzle->n != puzzle->n - 1)
				write(1, &" ", 1);
			j++;
		}
		write(1, &"\n", 1);
		i++;
	}
}

int	input_validation(int ac, char **av, t_puzzle *puzzle)
{
	if (ac != 2)
	{
		print_error(2);
		return (0);
	}
	if (check_av(av[1], puzzle) == 0)
	{
		print_error(2);
		return (0);
	}
	return (1);
}

void	free_puzzle(t_puzzle *puzzle)
{
	int	i;

	i = 0;
	if (puzzle->board)
	{
		while (i < puzzle->n)
		{
			free(puzzle->board[i]);
			i++;
		}
		free(puzzle->board);
	}
	if (puzzle->target)
		free(puzzle->target);
}

int	main(int ac, char **av)
{
	int			i;
	t_puzzle	puzzle;

	puzzle.n = 0;
	if (!input_validation(ac, av, &puzzle))
		return (0);
	puzzle.board = (int **)malloc(sizeof(int *) * puzzle.n);
	i = -1;
	while (++i < puzzle.n)
		puzzle.board[i] = (int *)malloc(sizeof(int) * puzzle.n);
	puzzle.target = (int *)malloc(sizeof(int) * (puzzle.n * 4));
	fill_target(&puzzle, av[1]);
	if (!target_isvalid(&puzzle))
	{
		print_error(2);
		return (free_puzzle(&puzzle), 0);
	}
	if (solve_puzzle(&puzzle, 0))
		display_solution(&puzzle);
	else
		print_error(2);
	free_puzzle(&puzzle);
	return (0);
}
