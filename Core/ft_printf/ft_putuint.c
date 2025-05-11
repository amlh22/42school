/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:12:12 by amho              #+#    #+#             */
/*   Updated: 2025/05/11 22:14:09 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putuint(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}
