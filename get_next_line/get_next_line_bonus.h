/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:06:09 by mraspors          #+#    #+#             */
/*   Updated: 2022/02/22 03:42:07 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *buf, int *loc);
char	*create_result(char *buf, int loc);
char	*fill_buf(char *buf, int loc);
int		ft_strlen(char *s);
int		ft_strchr(char *str, int *i, int *give_loc);
char	*ft_strjoin(char *s1, char *s2);

#endif