/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghattas <jghattas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:52:19 by jghattas          #+#    #+#             */
/*   Updated: 2024/07/18 01:28:53 by jghattas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		list_len;

	list_len = 0;
	va_start(list, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				list_len += cases(format, list);
		}
		else
			list_len += write(1, &(*format), 1);
		format++;
	}
	va_end(list);
	return (list_len);
}
