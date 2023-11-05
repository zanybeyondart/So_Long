/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinftf_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 04:16:49 by zvakil            #+#    #+#             */
/*   Updated: 2023/09/07 07:06:14 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	add(uintptr_t num)
{
	int		length;
	int		remainder;
	char	symbol;

	remainder = 0;
	length = 0;
	remainder = num % 16;
	if (remainder < 10)
		symbol = remainder + '0';
	else
		symbol = remainder - 10 + 'a';
	if (num >= 16)
		length += add(num / 16);
	length += print_char(symbol);
	return (length);
}

int	print_ptr(unsigned long ptr)
{
	int	length;

	write(1, "0x", 2);
	length = 2;
	if (ptr == 0)
		length += print_char('0');
	else
		length += add(ptr);
	return (length);
}

int	hex_add(unsigned int num, char c)
{
	int		len;
	int		rem;
	char	symbol;

	rem = 0;
	len = 0;
	rem = num % 16;
	if (rem < 10)
		symbol = rem + '0';
	else
	{
		if (c == 'x')
			symbol = rem - 10 + 'a';
		if (c == 'X')
			symbol = rem - 10 + 'A';
	}
	if (num >= 16)
		len += print_hex(num / 16, c);
	len += print_char(symbol);
	return (len);
}

int	print_hex(unsigned int num, char c)
{
	int	length;

	length = 0;
	if (num == 0)
		return (print_char('0'));
	else
		length += hex_add(num, c);
	return (length);
}
