/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 02:16:00 by zvakil            #+#    #+#             */
/*   Updated: 2023/08/13 16:16:29 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *a)
{
	size_t	b;

	b = 0;
	if (!a)
		return (b);
	while (a[b] != '\0')
		b++;
	return (b);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		b;
	int		c;	

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	b = 0;
	c = 0;
	s3 = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	while (s1[c] != '\0')
		s3[b++] = s1[c++];
	c = 0;
	while (s2[c] != '\0')
		s3[b++] = s2[c++];
	s3[b] = '\0';
	free(s1);
	return (s3);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

int	checknl(char *s, char c)
{
	int	a;

	a = 0;
	if (!s)
		return (0);
	while (s[a] != '\0')
	{
		if (s[a] == c)
			return (1);
		a++;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	if (n == 0)
		return (0);
	a = 0;
	while ((s1[a] || s2[a]) != '\0' && a < n - 1 && s1[a] == s2[a])
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
