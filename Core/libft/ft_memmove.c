/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:51:50 by amho              #+#    #+#             */
/*   Updated: 2024/11/12 00:44:16 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void*src, size_t len)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if (temp_dst <= temp_src)
		return (ft_memcpy(dst, src, len));
	if (temp_dst > temp_src)
		while (len--)
			temp_dst[len] = temp_src[len];
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
#include <assert.h>
int main()
{
    char s1[20];
    char s2[20];
    
    //NULL args
    assert(memmove(NULL, NULL, 0) == ft_memmove(NULL, NULL, 0));
    
    //Basic copy
    strcpy(s1, "Hello, World!");
    strcpy(s2, "Hello, World!");
    printf("Test 1 - Original:   %s\n", s1);
    memmove(s1 + 2, s1, 5);
    ft_memmove(s2 + 2, s2, 5);
    printf("memmove:    %s\n", s1);
    printf("ft_memmove: %s\n", s2);
    printf("Match: %s\n\n", (memcmp(s1, s2, strlen(s1)) == 0) ? "Yes" : "No");
    
    //Overlapping
    strcpy(s1, "abcdef");
    strcpy(s2, "abcdef");
    printf("Test 2 - Original:   %s\n", s1);
    memmove(s1 + 2, s1, 4);
    ft_memmove(s2 + 2, s2, 4);
    printf("memmove:    %s\n", s1);
    printf("ft_memmove: %s\n", s2);
    printf("Match: %s\n\n", (memcmp(s1, s2, strlen(s1)) == 0) ? "Yes" : "No");
    
    //Single character
    memset(s1, 0, 20);  
    memset(s2, 0, 20);
    s1[0] = 'X';
    s2[0] = 'X';
    printf("Test 3 - Original:   %s\n", s1);
    memmove(s1 + 1, s1, 1);
    ft_memmove(s2 + 1, s2, 1);
    printf("memmove:    %s\n", s1);
    printf("ft_memmove: %s\n", s2);
    printf("Match: %s\n\n", (memcmp(s1, s2, 2) == 0) ? "Yes" : "No");
    
    return (0);
}
*/