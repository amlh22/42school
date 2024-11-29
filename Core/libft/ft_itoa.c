/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:57:56 by amho              #+#    #+#             */
/*   Updated: 2024/11/23 11:25:49 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count++;
		if (n == 0)
			return (count);
		n = -n;
	}
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static void	fill_str(char *str, int n, int len)
{
	int	i;

	i = len - 1;
	if (n == 0)
		str[i] = '0';
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;
	int		sign;

	digits = count_digits(n);
	sign = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	str = malloc(digits + 1);
	if (!str)
		return (NULL);
	str[digits] = '\0';
	if (n == 0)
		str[0] = '0';
	else
		fill_str(str, n, digits);
	if (sign == -1)
		str[0] = '-';
	return (str);
}
