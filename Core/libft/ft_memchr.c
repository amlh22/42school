/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:44:50 by amho              #+#    #+#             */
/*   Updated: 2024/11/12 01:06:21 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	temp_c;
	unsigned char	*temp_s;

	temp_c = (unsigned char)c;
	temp_s = (unsigned char *)s;
	while (n > 0)
	{
		if (*temp_s == temp_c)
			return ((void *)temp_s);
		temp_s++;
		n--;
	}
	return (NULL);
}
