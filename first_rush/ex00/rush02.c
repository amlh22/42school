/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:25:59 by amho              #+#    #+#             */
/*   Updated: 2024/08/25 15:00:07 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	write_line(int length, char first, char last, char fill)
{
	ft_putchar(first);
	while (length > 2)
	{
		ft_putchar(fill);
		length--;
	}
	if (length == 2)
	{
		ft_putchar(last);
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	height;

	if (x <= 0 || y <= 0)
		return ;
	height = y;
	while (height >= 1)
	{
		if (height == y)
		{
			write_line(x, 'A', 'A', 'B');
		}
		else if (height == 1)
		{
			write_line(x, 'C', 'C', 'B');
		}
		else
		{
			write_line(x, 'B', 'B', ' ');
		}
		height--;
	}
}
