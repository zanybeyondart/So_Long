/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 04:35:56 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/05 08:52:48 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../get_next_line/get_next_line.h"

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

int		ft_putnbr(int nbr);
int		ft_printf(const char *a, ...);
int		printer(const char *a);
int		print_char(char c);
int		print_ptr(unsigned long ptr);
int		ft_hex_helper(unsigned int num, char c);
int		print_hex(unsigned int num, char c);
int		print_str(const char *str);
int		print_int(int a);
int		print_uint(unsigned int n);
int		print_add(uintptr_t num);
int		print_hex(unsigned int num, char c);
int		ft_hex_helper(unsigned int num, char c);

#endif