/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:31:41 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/28 14:04:17 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	check_matrix_1(int **mat, int row, int col, t_map_errs *err)
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
	t_map_errs	*err;

	err = malloc (sizeof(t_map_errs));
	err->w = 0;
	err->c = 0;
	err->p = 0;
	err->e = 0;
	check_matrix_1(mat, row, col, err);
	if (err->w == -1 || err->c == 0 || err->e != 1 || err->p != 1)
	{
		if (err->w == -1)
			printf("Invalid Wall: Check borders\n");
		else if (err->c == 0)
			printf("Invalid Collectible : Put atleast one collectible\n");
		else if (err->e != 1)
			printf("Invalid Exit : There should be 1 exit\n");
		else if (err->p != 1)
			printf("Invalid Wall : There should be 1 player\n");
		free(err);
		return (0);
	}
	free(err);
	return (1);
}

int	set_r_c(int *rc, char *path)
{
	char	*temp;
	int		fd;

	fd = open(path, O_RDONLY);
	temp = get_next_line(fd);
	rc[1] = -1;
	rc[0] = 0;
	while (temp != NULL)
	{
		if (rc[1] == -1)
			rc[1] += ft_strlen(temp);
		rc[0]++;
		free(temp);
		temp = get_next_line(fd);
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
	free(temp);
	return (row);
}

int	**matrix_create(int *rc, int **mat, char *path)
{
	int	i;
	int	fd;

	fd = open(path, O_RDONLY);
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
