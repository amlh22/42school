/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:56:56 by amho              #+#    #+#             */
/*   Updated: 2024/11/16 16:59:21 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (haystack == NULL && len == 0)
		return (NULL);
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	while (*haystack && len >= needle_len)
	{
		if (*haystack == *needle)
		{
			if (ft_strncmp(haystack, needle, needle_len) == 0)
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
    char str1[] = "Hello World";
    printf("strnstr:    %s\n", strnstr(str1, "World", strlen(str1)));
    printf("ft_strnstr: %s\n", ft_strnstr(str1, "World", strlen(str1)));
    
    printf("strnstr:    %s\n", strnstr(str1, "Bye", strlen(str1)));
    printf("ft_strnstr: %s\n", ft_strnstr(str1, "Bye", strlen(str1)));
    
    printf("strnstr:    %s\n", strnstr(str1, "", strlen(str1)));
    printf("ft_strnstr: %s\n", ft_strnstr(str1, "", strlen(str1)));
    
    printf("strnstr:    %s\n", strnstr(NULL, "test", 0));
    printf("ft_strnstr: %s\n", ft_strnstr(NULL, "test", 0));
    
    return (0);
}
*/