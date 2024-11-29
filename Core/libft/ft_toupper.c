/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:10:47 by amho              #+#    #+#             */
/*   Updated: 2024/11/09 17:14:04 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 97 + 65);
	return (c);
}
/*
#include <ctype.h>
int main() {
    int c = 'm';
    printf("%d\n", ft_toupper(c));
    printf("%d\n", toupper(c));

    return 0;
}
*/