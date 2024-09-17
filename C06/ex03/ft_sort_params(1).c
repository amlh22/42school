/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:48:51 by amho              #+#    #+#             */
/*   Updated: 2024/09/11 19:50:22 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_swap(char **a, char **b)
{
	char	*swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	sort_args(char *tab[], int size)
{
	int	i;
	int	sorted;

	if (size <= 1)
		return ;
	while (1)
	{
		sorted = 1;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i][0] > tab [i + 1][0])
			{
				ft_swap(&tab[i], &tab[i +1]);
				sorted = 0;
			}
			i++;
		}
		if (sorted == 1)
			break ;
	}
}

int	main(int ac, char *av[])
{
	int	i;

	sort_args(av + 1, ac - 1);
	i = 1;
	while (i < ac)
	{
		ft_putstr(av[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
