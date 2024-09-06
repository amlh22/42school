/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:38:25 by amho              #+#    #+#             */
/*   Updated: 2024/08/25 18:06:02 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	string_to_int(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			return (-1);
		}
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	if (argc == 3)
	{
		x = string_to_int(argv[1]);
		y = string_to_int(argv[2]);
	}
	else
	{
		return (-1);
	}
	rush(x, y);
	return (0);
}
