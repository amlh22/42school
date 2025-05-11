/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:54:36 by amho              #+#    #+#             */
/*   Updated: 2025/05/11 21:07:12 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_formats(va_list args, const char **fmt)
{
	int	count;

	count = 0;
	if (**fmt == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (**fmt == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (**fmt == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (**fmt == 'd' || **fmt == 'i')
		count += ft_putint(va_arg(args, int));
	else if (**fmt == 'u')
		count += ft_putuint(va_arg(args, unsigned int));
	else if (**fmt == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 0);
	else if (**fmt == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 1);
	else if (**fmt == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	count;

	if (!format)
		return (0);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_formats(args, &format);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
