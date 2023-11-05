/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 04:18:10 by zvakil            #+#    #+#             */
/*   Updated: 2023/09/07 07:07:28 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(const char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd ((char *) str, 1);
	return (ft_strlen(str));
}

int	print_int(int a)
{
	return (ft_putnbr (a));
}

int	print_uint(unsigned int n)
{
	char	a;
	int		len;

	len = 0;
	if (n == 4294967295)
	{
		write (1, "4294967295", 10);
		return (10);
	}
	if (n >= 10)
		len += print_uint (n / 10);
	a = (n % 10) + '0';
	len += print_char(a);
	return (len);
}

int	print_add(uintptr_t num)
{
	int		length;
	int		reminder;
	char	symbol;

	reminder = 0;
	length = 0;
	reminder = num % 16;
	if (reminder < 10)
		symbol = reminder + '0';
	else
		symbol = reminder - 10 + 'a';
	if (num >= 16)
		length += print_add(num / 16);
	ft_putchar_fd (symbol, 1);
	return (length);
}
