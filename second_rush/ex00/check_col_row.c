#include "puzzle.h"

int	is_doubles(t_puzzle *puzzle, int i, int pos)
{
	int	j;
	int	row;
	int	col;

	row = pos / puzzle->n;
	col = pos % puzzle->n;
	j = 0;
	while (j < puzzle->n)
	{
		if (puzzle->board[j][col] == i || puzzle->board[row][j] == i)
			return (0);
		j++;
	}
	return (1);
}

int	check_up_col(t_puzzle *puzzle, int i, int pos)
{
	int	v_tower;
	int	j;
	int	tallest;

	if (pos / puzzle->n < (puzzle->n - 1))
		return (1);
	puzzle->board[pos / puzzle->n][pos % puzzle->n] = i;
	j = 0;
	v_tower = 1;
	tallest = puzzle->board[0][pos % puzzle->n];
	while (j < puzzle->n)
	{
		if (puzzle->board[j][pos % puzzle->n] > tallest)
		{
			tallest = puzzle->board[j][pos % puzzle->n];
			v_tower++;
		}
		j++;
	}
	if (v_tower != puzzle->target[pos % puzzle->n])
	{
		puzzle->board[pos / puzzle->n][pos % puzzle->n] = 0;
		return (0);
	}
	return (1);
}

int	check_down_col(t_puzzle *puzzle, int i, int pos)
{
	int	v_tower;
	int	j;
	int	tallest;

	if (pos / puzzle->n < (puzzle->n - 1))
		return (1);
	puzzle->board[pos / puzzle->n][pos % puzzle->n] = i;
	j = (puzzle->n - 1);
	v_tower = 1;
	tallest = puzzle->board[puzzle->n - 1][pos % puzzle->n];
	while (j >= 0)
	{
		if (puzzle->board[j][pos % puzzle->n] > tallest)
		{
			tallest = puzzle->board[j][pos % puzzle->n];
			v_tower++;
		}
		j--;
	}
	if (v_tower != puzzle->target[(pos % puzzle->n) + puzzle->n])
	{
		puzzle->board[pos / puzzle->n][pos % puzzle->n] = 0;
		return (0);
	}
	return (1);
}

int	check_right_row(t_puzzle *puzzle, int i, int pos)
{
	int	v_tower;
	int	j;
	int	tallest;

	if (pos % puzzle->n < (puzzle->n - 1))
		return (1);
	puzzle->board[pos / puzzle->n][pos % puzzle->n] = i;
	j = (puzzle->n - 1);
	v_tower = 1;
	tallest = puzzle->board[pos / puzzle->n][puzzle->n - 1];
	while (j >= 0)
	{
		if (puzzle->board[pos / puzzle->n][j] > tallest)
		{
			tallest = puzzle->board[pos / puzzle->n][j];
			v_tower++;
		}
		j--;
	}
	if (v_tower != puzzle->target[(pos / puzzle->n) + (puzzle->n * 3)])
	{
		puzzle->board[pos / puzzle->n][pos % puzzle->n] = 0;
		return (0);
	}
	return (1);
}

int	check_left_row(t_puzzle *puzzle, int i, int pos)
{
	int	v_tower;
	int	j;
	int	tallest;

	if (pos % puzzle->n < (puzzle->n -1))
		return (1);
	puzzle->board[pos / puzzle->n][pos % puzzle->n] = i;
	j = 0;
	v_tower = 1;
	tallest = puzzle->board[pos / puzzle->n][0];
	while (j < puzzle->n)
	{
		if (puzzle->board[pos / puzzle->n][j] > tallest)
		{
			tallest = puzzle->board[pos / puzzle->n][j];
			v_tower++;
		}
		j++;
	}
	if (v_tower != puzzle->target[(pos / puzzle->n) + (puzzle->n * 2)])
	{
		puzzle->board[pos / puzzle->n][pos % puzzle->n] = 0;
		return (0);
	}
	return (1);
}
