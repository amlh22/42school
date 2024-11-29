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
