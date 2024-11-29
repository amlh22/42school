/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:29:38 by amho              #+#    #+#             */
/*   Updated: 2024/11/23 14:14:56 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static void	ft_free(char **result, int count)
{
	while (count > 0)
	{
		free(*result);
		result++;
		count--;
	}
	free(result);
}

static void	ft_fill_arr(char **arr, char const *s, char sep)
{
	char		**pos;
	const char	*start;

	pos = arr;
	while (*s)
	{
		while (*s == sep)
			++s;
		start = s;
		while (*s && *s != sep)
			++s;
		if (s > start)
		{
			*pos = ft_substr(start, 0, s - start);
			if (!*pos)
			{
				ft_free(arr, pos - arr);
				return ;
			}
			++pos;
		}
	}
	*pos = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count(s, c);
	result = malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (NULL);
	ft_fill_arr(result, s, c);
	return (result);
}
