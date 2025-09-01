/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghattas <jghattas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:36:38 by jghattas          #+#    #+#             */
/*   Updated: 2024/08/11 11:35:27 by jghattas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		cases(const char *format, va_list list);
int		ft_putchar_fd(int c, int fd);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_unsigned(unsigned int n);
size_t	hexa(unsigned int n, bool upper_case);
size_t	ft_strcpy(char *dest, char *src);
int		prt_ptr(void *addr);

#endif