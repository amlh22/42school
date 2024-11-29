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
