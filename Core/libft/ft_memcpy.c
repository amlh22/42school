/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 23:08:48 by amho              #+#    #+#             */
/*   Updated: 2024/11/20 11:24:08 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if (n == 0)
		return (dst);
	while (n > 0)
	{
		*temp_dst++ = *temp_src++;
		n--;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char s1[] = "Hello";
	char s2[10];
	char s3[10];
	int n1[] = {1,2,3};
	int n2[3];
	int n3[3];

	// Test NULL pointers. Not handled by original.
	printf("ft_memcpy(NULL, NULL, 3): %p\n", ft_memcpy(NULL, NULL, 3));
	printf("   memcpy(NULL, NULL, 3): %p\n", memcpy(NULL, NULL, 3));

	//Copy string
	ft_memcpy(s2, s1, 6);
	memcpy(s3, s1, 6);
	printf("ft_memcpy: %s\n", s2);
	printf("   memcpy: %s\n", s3);

	//Array
	ft_memcpy(n2, n1, sizeof(n1));
	memcpy(n3, n1, sizeof(n1));
	printf("ft_memcpy: %d %d %d\n", n2[0], n2[1], n2[2]);
	printf("   memcpy: %d %d %d\n", n3[0], n3[1], n3[2]);

	return (0);
}
*/
