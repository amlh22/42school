/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:56:16 by amho              #+#    #+#             */
/*   Updated: 2024/11/16 14:39:28 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int main(void) {
	int var = '9';
	printf("%d\n", ft_isdigit(var));
	printf("%d\n", isdigit(var));
	return (0);
}*/
