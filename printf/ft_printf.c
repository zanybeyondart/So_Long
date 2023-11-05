/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 22:36:05 by zvakil            #+#    #+#             */
/*   Updated: 2023/09/07 07:06:39 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	args(va_list list, char c)
{
	int	len;

	len = 0;
	if (c == 's')
		len = print_str (va_arg(list, const char *));
	else if (c == 'i' || c == 'd')
		len = print_int (va_arg(list, int));
	else if (c == '%')
		len = print_char ('%');
	else if (c == 'u')
		len = print_uint(va_arg(list, unsigned int));
	else if (c == 'p')
		len = print_ptr (va_arg(list, unsigned long));
	else if (c == 'x' || c == 'X')
		len = print_hex (va_arg(list, unsigned int), c);
	else if (c == 'c')
		len = print_char (va_arg(list, int));
	return (len);
}

int	ft_printf(const char *a, ...)
{
	va_list	list;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start (list, a);
	while (a[i] != '\0')
	{
		if (a[i] == '%')
		{
			len += args(list, a[i + 1]);
			i += 2;
		}
		else
		{
			len += print_char(a[i]);
			i++;
		}
	}
	va_end (list);
	return (len);
}
