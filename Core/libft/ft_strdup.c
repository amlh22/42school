/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:51:28 by amho              #+#    #+#             */
/*   Updated: 2024/11/13 23:12:03 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s1);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s1, len + 1);
	return (dup);
}
/*
void	tester(const char *input)
{
	char *test_ft = ft_strdup(input);
	char *test_lib = strdup(input);

	printf("ft_strdup: %s\n", test_ft);
	printf("strdup: %s\n", test_lib);
	free(test_ft);
	free(test_lib);
}

int main(void)
{
	char *arr[] = {
		"Hello world!",
		"12345",
		"",
		"NULL",
		"-<*&^"
	};

	int num = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < num; i++)
		tester(arr[i]);
	return (0);
}
*/
