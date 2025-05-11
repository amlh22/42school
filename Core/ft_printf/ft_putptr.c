/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:02:24 by amho              #+#    #+#             */
/*   Updated: 2025/05/11 23:09:36 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	add;
	int				count;

	count = 0;
	add = (unsigned long)ptr;
	count += ft_putstr("0x");
	count += ft_puthex(add, 0);
	return (count);
}
