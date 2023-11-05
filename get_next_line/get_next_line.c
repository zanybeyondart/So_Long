/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 02:10:12 by zvakil            #+#    #+#             */
/*   Updated: 2023/08/13 16:05:08 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*assigning_line(char *str, int fd)
{
	char	*buffer;
	int		r_val;

	buffer = (char *) malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	r_val = 1;
	while (r_val != 0 && checknl(str, '\n') == 0)
	{
		r_val = read (fd, buffer, BUFFER_SIZE);
		if (r_val == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[r_val] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*fix_line(char *str)
{
	int		a;
	int		b;
	char	*line;

	b = 0;
	a = 0;
	while (str[a] != '\n' && str[a] != '\0')
		a++;
	if (str[a] == '\n')
		a++;
	line = (char *) malloc (a + 1);
	if (!line)
		return (NULL);
	while (b < a)
	{
		line[b] = str[b];
		b++;
	}
	line[b] = '\0';
	return (line);
}

char	*remaining(char *str)
{
	char	*temp;
	int		a;
	int		len;
	int		b;

	a = 0;
	while (str[a] != '\n' && str[a] != '\0')
		a++;
	if (str[a] == '\n')
		a++;
	len = ft_strlen(str) - a;
	if (len == 0)
	{
		temp = (char *) malloc (1);
		temp[0] = '\0';
		free(str);
		return (temp);
	}
	b = 0;
	temp = (char *)malloc (len + 1);
	while (str[a] != '\0')
		temp[b++] = str[a++];
	temp[b] = '\0';
	free(str);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	str = assigning_line(str, fd);
	if (ft_strlen(str) == 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	line = fix_line(str);
	str = remaining(str);
	return (line);
}
