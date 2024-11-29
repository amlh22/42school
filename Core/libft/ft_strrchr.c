/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:16:33 by amho              #+#    #+#             */
/*   Updated: 2024/11/20 10:26:53 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		temp_c;
	const char	*last_c;

	temp_c = (char)c;
	last_c = NULL;
	if (temp_c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == temp_c)
			last_c = s;
		s++;
	}
	return ((char *)last_c);
}
/*
#include <stdio.h>
#include <string.h>
int main(void) 
{
    const char *str1 = "Hello, world!";
    const char *str2 = "0123456";
    const char *str3 = "";
    const char *str4 = "abced_______  abcd";
    
    char *result1 = ft_strrchr(str1, 'o');
    char *result2 = strrchr(str1, 'o');
    printf("Test 1: %s (libft) vs %s (stdlib)\n", result1, result2);
    
    char *result3 = ft_strrchr(str2, '1');
    char *result4 = strrchr(str2, '1');
    printf("Test 2: %s (libft) vs %s (stdlib)\n", result3, result4);
    
    char *result5 = ft_strrchr(str3, '\0');
    char *result6 = strrchr(str3, '\0');
    printf("Test 3: %s (libft) vs %s (stdlib)\n", result5, result6);
    
    char *result7 = ft_strrchr(str4, '_');
    char *result8 = strrchr(str4, '_');
    printf("Test 4: %s (libft) vs %s (stdlib)\n", result7, result8);
    
    char *result9 = ft_strrchr(str3, '4');
    char *result10 = strrchr(str3, '4');
    printf("Test 5: %s (libft) vs %s (stdlib)\n", result9, result10);
}
*/