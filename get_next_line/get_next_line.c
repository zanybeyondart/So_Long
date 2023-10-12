/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:05:23 by mraspors          #+#    #+#             */
/*   Updated: 2022/02/22 03:24:45 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_buf(char *buf, int loc)
{
	char	*result;

	result = NULL;
	if (loc == -1)
		result = NULL;
	else
		result = ft_strjoin(NULL, &buf[loc + 1]);
	free(buf);
	buf = NULL;
	return (result);
}

char	*create_result(char *buf, int loc)
{
	char	c;
	char	*result;

	if (!buf)
		return (NULL);
	if (loc == -1)
	{
		result = ft_strjoin(NULL, buf);
		return (result);
	}
	c = buf[loc + 1];
	buf[loc + 1] = '\0';
	result = ft_strjoin(NULL, buf);
	buf[loc + 1] = c;
	return (result);
}

char	*ft_read(int fd, char *buf, int *loc)
{
	char	s[BUFFER_SIZE + 1];
	int		read_c;
	int		i;

	i = 0;
	read_c = 0;
	while (ft_strchr(buf, &i, loc) == -1)
	{
		read_c = read(fd, s, BUFFER_SIZE);
		if (read_c <= 0)
			break ;
		s[read_c] = '\0';
		buf = ft_strjoin(buf, s);
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*result;
	int			loc;

	loc = 0;
	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buf = ft_read(fd, buf, &loc);
	if (buf == NULL)
		return (NULL);
	result = create_result(buf, loc);
	buf = fill_buf(buf, loc);
	if (result[0] == '\0')
		result = NULL;
	return (result);
}
