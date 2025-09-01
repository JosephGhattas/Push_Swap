/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghattas <jghattas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 23:27:15 by jghattas          #+#    #+#             */
/*   Updated: 2024/08/11 11:35:48 by jghattas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(int c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	else
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = (-n);
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar_fd(n % 10 + '0', 1);
	return (count);
}

int	ft_unsigned(unsigned int n)
{
	int		count;
	char	digit;
	char	digits[10];

	ft_strcpy(digits, "0123456789");
	count = 0;
	if (n >= 10)
		count += ft_unsigned(n / 10);
	digit = digits[n % 10];
	count += ft_putchar_fd(digit, 1);
	return (count);
}

size_t	hexa(unsigned int n, bool upper_case)
{
	size_t			digits;
	static char		upper_digits[16];
	static char		lower_digits[16];

	digits = 0;
	ft_strcpy(upper_digits, "0123456789ABCDEF");
	ft_strcpy(lower_digits, "0123456789abcdef");
	if (n == 0)
		return (ft_putchar_fd('0', 1));
	if (n >= 16)
		digits += hexa(n / 16, upper_case);
	if (upper_case == true)
		digits += ft_putchar_fd(upper_digits[n % 16], 1);
	else
		digits += ft_putchar_fd(lower_digits[n % 16], 1);
	return (digits);
}
