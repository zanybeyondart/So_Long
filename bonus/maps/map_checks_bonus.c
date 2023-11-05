/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:42:32 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/05 09:05:35 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

int	check_valid_alpha(char c)
{
	if (c == '1' || c == '\n' || c == '0'
		|| c == 'C' || c == 'P' || c == 'E'
		|| c == 'V')
		return (1);
	return (0);
}

int	check_map(char *path)
{
	int		i;
	int		len;
	int		fd;
	char	*temp;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_return(1, 0, NULL, 0);
	temp = get_next_line(fd);
	len = ft_strlen(temp);
	while (temp != NULL && (int)ft_strlen(temp) == len)
	{
		i = 0;
		while (check_valid_alpha(temp[i]))
			i++;
		if (temp[i] != '\0')
			error_return(2, fd, temp, temp[i]);
		free(temp);
		temp = get_next_line(fd);
	}
	if (temp)
		free(temp);
	close (fd);
	return (1);
}
