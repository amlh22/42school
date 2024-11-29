/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:36:47 by amho              #+#    #+#             */
/*   Updated: 2024/11/13 20:34:27 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bites;
	char	*ptr;

	if (nmemb && size > SIZE_MAX / nmemb)
		return (NULL);
	bites = nmemb * size;
	ptr = malloc(bites);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, bites);
	return (ptr);
}
/*
#include <stdio.h>
int main()
{
    size_t nmemb = 0;
    size_t size = sizeof(int);
    int *arr = (int *)ft_calloc(nmemb, size);
    
    printf("ft_calloc pointer: %p\n", (void *)arr);

    for (size_t i = 0; i < nmemb; i++) {
        printf("arr[%zu] = %d\n", i, arr[i]);
    }

    free(arr);

    return 0;
}
*/
