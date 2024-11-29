/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:51:40 by amho              #+#    #+#             */
/*   Updated: 2024/11/20 11:35:07 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	src_len = ft_strlen(src);
	if (!dest && size == 0)
		return (src_len);
	dest_len = ft_strlen(dest);
	i = 0;
	j = dest_len;
	if (size <= dest_len)
		return (size + src_len);
	while (src[i] != '\0' && j < size - 1)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest_len + src_len);
}
/*
int main(void)
{
	char s1[20] = "r-----"; 	
	char *s2 = "lorem";
	size_t size1 = 15;

	printf("%zu\n", ft_strlcat(s1, s2, size1));
	printf("Resulting string: %s\n", s1);
	
	return (0);
}
*/
