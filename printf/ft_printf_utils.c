/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 03:43:57 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/05 08:54:01 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	a;

	if (!s)
		return ;
	a = 0;
	while (s[a] != '\0')
		write(fd, &s[a++], 1);
}

int	ft_putnbr(int nbr)
{
	char	c;
	int		length;

	length = 0;
	if (nbr == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		length += print_char('-');
		nbr *= -1;
	}
	if (nbr >= 10)
		length += ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	length += print_char(c);
	return (length);
}
