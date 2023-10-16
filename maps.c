/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:20:29 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/16 18:39:17 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	check_matrix_1(int **mat, int row, int col, map_errs *err)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if ((mat[i][0] != 1 || mat[i][col - 1] != 1)
				|| ((i == 0 || i == row - 1) && mat[i][j] != 1))
				err->w = -1;
			if (mat[i][j] == P)
				err->p++;
			if (mat[i][j] == E)
				err->e++;
			if (mat[i][j] == C)
				err->c++;
			j++;
		}
		i++;
	}
}

int	check_matrix(int **mat, int row, int col)
{
	map_errs	*err;

	err = malloc (sizeof(map_errs));
	err->w = 0;
	err->c = 0;
	err->p = 0;
	err->e = 0;
	check_matrix_1(mat, row, col, err);
	if (err->w == -1 || err->c == 0 || err->e != 1 || err->p != 1)
	{
		free(err);
		return (0);
	}
	else
	{
		free(err);
		return (1);
	}
}

int	set_r_c(int *rc)
{
	char	*temp;
	int		fd;

	fd = open("./map1.ber", O_RDONLY);
	rc[1] = -1;
	rc[0] = -1;
	while (temp != NULL)
	{
		temp = get_next_line(fd);
		if (rc[1] == -1)
			rc[1] += ft_strlen(temp);
		rc[0]++;
	}
	close(fd);
	return (1);
}

int	*fill_row(int *row, int fd, int lim)
{
	char	*temp;
	int		i;

	i = 0;
	temp = get_next_line(fd);
	while (i < lim)
	{
		row[i] = temp[i] - 48;
		i++;
	}
	return (row);
}

int	**matrix_create(int *rc, int **mat)
{
	int	i;
	int	fd;

	fd = open("./map1.ber", O_RDONLY);
	i = 0;
	mat = malloc(sizeof(int *) * rc[0]);
	while (i < rc[0])
	{
		mat[i] = malloc(sizeof(int) * rc[1]);
		mat[i] = fill_row(mat[i], fd, rc[1]);
		i++;
	}
	close (fd);
	return (mat);
}

int	check_map(void)
{
	int		i;
	int		len;
	int		fd;
	char	*temp;

	fd = open("./map1.ber", O_RDONLY);
	temp = get_next_line(fd);
	len = ft_strlen(temp);
	while (temp != NULL && ft_strlen(temp) == len)
	{
		i = 0;
		while (temp[i] == '1' || temp[i] == '\n' || temp[i] == '0'
			|| temp[i] == 'C' || temp[i] == 'P' || temp[i] == 'E')
			i++;
		if (temp[i] != '\0')
		{
			close (fd);
			return (0);
		}
		temp = get_next_line(fd);
	}
	close (fd);
	return (1);
}

int	path_valid(int **mat)
{
 return (1);
}

int	main()
{
	int	rc[2];
	int	**mat;

	if (check_map() && set_r_c(rc))
		mat = matrix_create(rc, mat);
	if (mat && check_matrix(mat, rc[0], rc[1]) && path_valid(mat))
		game_start(mat, rc);
	else
		free(mat);
	return (0);
}