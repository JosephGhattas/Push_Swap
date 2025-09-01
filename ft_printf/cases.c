/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghattas <jghattas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:29:43 by jghattas          #+#    #+#             */
/*   Updated: 2024/08/11 11:31:23 by jghattas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cases(const char *format, va_list list)
{
	int	len;

	len = 0;
	if (*format == 'c')
	{
		len += ft_putchar_fd(va_arg(list, int), 1);
	}
	else if (*format == 's')
		len += ft_putstr(va_arg(list, char *));
	else if (*format == 'p')
		len += prt_ptr(va_arg(list, void *));
	else if (*format == 'd' || *format == 'i')
		len += ft_putnbr(va_arg(list, int));
	else if (*format == 'u')
		len += ft_unsigned(va_arg(list, unsigned int));
	else if (*format == 'x')
		len += hexa((va_arg(list, size_t)), false);
	else if (*format == 'X')
		len += hexa((va_arg(list, size_t)), true);
	else if (*format == '%')
		len += ft_putchar_fd('%', 1);
	else
		len += ft_putchar_fd(*format, 1);
	return (len);
}
