/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:03:39 by amho              #+#    #+#             */
/*   Updated: 2024/09/12 12:06:46 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char *src1 = "Hello, World!";
    char *src2 = "This is a test string";
    char *src3 = "";
    char *dst1 = ft_strdup(src1);
    char *dst2 = ft_strdup(src2);
    char *dst3 = ft_strdup(src3);

    printf("Original: %s, Duplicate: %s\n", src1, dst1);
    printf("Original: %s, Duplicate: %s\n", src2, dst2);
    printf("Original: %s, Duplicate: %s\n", src3, dst3);
	
	free(dst1);
    free(dst2);
    free(dst3);
	return (0);
}*/
