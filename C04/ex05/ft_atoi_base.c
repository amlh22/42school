/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:07:47 by amho              #+#    #+#             */
/*   Updated: 2024/09/10 13:19:34 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c)
{
	if ((c => 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	valid_base(char *base)
{
	int	i;
	int	j;

	if (!base || !base[0] || !base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	base_index(char *base, char c, int *base_i)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
		{
			*base_i = i;
			return (i);
		}
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	base_i;
	int	base_len;

	result = 0;
	sign = 1;
	base_i = 0;
	base_len = valid_base(base);
	if (base_len < 2)
		return (0);
	while (ft_isspace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (base_index(base, *str++, &base_i) != -1)
		result = (result * base_len) + base_i;
	return (sign * result);
}
