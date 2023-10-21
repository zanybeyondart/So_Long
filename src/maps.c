/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:20:29 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/21 15:17:49 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	error_return(int er, int fd, char *temp, char c)
{
	if (er == 1)
	{
		perror("Invalid Map");
		exit(1);
	}
	if (er == 2)
	{
		close (fd);
		printf("Invalid Char found : '%c' \n", c);
		free(temp);
		exit(1);
	}
}

void	matrix_free(int **mat, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
		free(mat[i++]);
	free(mat);
}

void	free_map(map *map)
{
	if (map)
	{
		matrix_free(map->mat, map->rc[0]);
		free(map);
	}
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
	while (temp != NULL && ft_strlen(temp) == len)
	{
		i = 0;
		while (temp[i] == '1' || temp[i] == '\n' || temp[i] == '0'
			|| temp[i] == 'C' || temp[i] == 'P' || temp[i] == 'E')
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

int	main(int ac, char **av)
{
	int	rc[2];
	int	path[1];
	int	**mat;
	int	start[2];

	mat = NULL;
	path[0] = 0;
	if (ac != 2)
	{
		printf("Invalid Arguments\n");
		exit(1);
	}
	if (check_map(av[1]) && set_r_c(rc, av[1]))
		mat = matrix_create(rc, mat, av[1]);
	start[0] = 0;
	start[1] = 0;
	ulti_path_check(mat, av[1], start, rc);
	check_errors(rc, mat);
	game_start(mat, rc);
	return (0);
}
