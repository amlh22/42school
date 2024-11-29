/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:02:21 by amho              #+#    #+#             */
/*   Updated: 2024/11/12 13:56:15 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*temp_s1 != *temp_s2)
			return (*temp_s1 - *temp_s2);
		temp_s1++;
		temp_s2++;
	}
	return (0);
}
/*
void tester(const void *s1, const void *s2, size_t n)
{
	int ft_result = ft_memcmp(s1, s2, n);
	int lib_result = memcmp(s1, s2, n);

	printf("ft_memcmp: %d\n", ft_result);
    	printf("memcmp: %d\n", lib_result);
}

int main(void)
{
	char str1[] = "";
	char str2[] = "";
	tester(str1, str2, 0);

	char str3[] = "hello";
	char str4[] = "hell0";
	tester(str3, str4, 5);

	char str5[] = "1234";
	char str6[] = "1204";
	tester(str5, str6, 4);

	char str7[] = "<>)!@£";
	char str8[] = "<>)_@$";
	tester(str7, str8, 6);

	return (0);
}
*/		
