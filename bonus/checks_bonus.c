/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:42:55 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/05 09:06:05 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	game_checks(t_vars *vars)
{
	int	j;
	int	i;
	int	c;

	c = 0;
	i = 0;
	j = 0;
	while (i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			if (vars->map->mat[i][j] == C)
				c++;
			j++;
		}
		j = 0;
		i++;
	}
	if (c == 0)
		vars->exit->exit = 1;
}

void	mediator(char *path, int **mat, int *index, int *rc)
{
	int	**temp;
	int	er[1];

	temp = NULL;
	er[0] = 0;
	temp = matrix_create(rc, temp, path);
	path_valid(temp, index[0], index[1], er);
	if (er[0] != 1)
	{
		ft_printf("No Valid Path\n");
		matrix_free(mat, rc[0]);
		matrix_free(temp, rc[0]);
		exit(1);
	}
	matrix_free(temp, rc[0]);
}

int	ulti_path_check(int **mat, char *path, int *start, int *rc)
{
	if (start[0] == rc[0] - 1 && start[1] == rc[1] - 1)
		return (mat[start[0]][start[1]]);
	if (mat[start[0]][start[1]] == C || mat[start[0]][start[1]] == P)
		mediator(path, mat, start, rc);
	if (start[1] == rc[1] - 1)
	{
		start[0]++;
		start[1] = 0;
		return (ulti_path_check(mat, path, start, rc));
	}
	start[1]++;
	return (ulti_path_check(mat, path, start, rc));
}

void	path_valid(int **mat, int i, int j, int *path)
{
	if (mat[i][j] == 1)
		return ;
	if (mat[i][j] == E)
	{
		path[0] = 1;
		return ;
	}
	mat[i][j] = 1;
	path_valid(mat, i - 1, j, path);
	path_valid(mat, i + 1, j, path);
	path_valid(mat, i, j - 1, path);
	path_valid(mat, i, j + 1, path);
}
