/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 02:12:03 by zvakil            #+#    #+#             */
/*   Updated: 2023/08/13 16:13:17 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*assigning_line(char *str, int fd);
char	*fix_line(char *str);
char	*remaining(char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		checknl(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *a);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif