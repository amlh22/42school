/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:24:53 by amho              #+#    #+#             */
/*   Updated: 2024/11/12 00:30:10 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	temp_c;

	temp_c = c;
	while (*s != temp_c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
/*
#include <stdio.h>
#include <string.h>
int main(void) 
{
    const char *str1 = "Hello, world!";
    const char *str2 = "012341560";
    const char *str3 = "";
    const char *str4 = "abced_______  abcd";
    
    char *result1 = ft_strchr(str1, 'o');
    char *result2 = strchr(str1, 'o');
    printf("Test 1: %s (libft) vs %s (stdlib)\n", result1, result2);
    
    char *result3 = ft_strchr(str2, '1');
    char *result4 = strchr(str2, '1');
    printf("Test 2: %s (libft) vs %s (stdlib)\n", result3, result4);
    
    char *result5 = ft_strchr(str3, '\0');
    char *result6 = strchr(str3, '\0');
    printf("Test 3: %s (libft) vs %s (stdlib)\n", result5, result6);
    
    char *result7 = ft_strchr(str4, '_');
    char *result8 = strchr(str4, '_');
    printf("Test 4: %s (libft) vs %s (stdlib)\n", result7, result8);
    
    char *result9 = ft_strchr(str3, '4');
    char *result10 = strrchr(str3, '4');
    printf("Test 5: %s (libft) vs %s (stdlib)\n", result9, result10);
}
*/