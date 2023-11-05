/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:42:55 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/05 09:24:34 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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
	t_map	*temp;
	int		er[1];

	temp = NULL;
	temp = malloc(sizeof(t_map));
	temp->mat = NULL;
	temp->rc = NULL;
	er[0] = 0;
	temp->mat = matrix_create(rc, mat, path);
	temp->rc = rc;
	path_valid(temp, index[0], index[1], er);
	if (er[0] != 1)
	{
		printf("No Valid Path\n");
		free_map(temp);
		exit(1);
	}
	free_map(temp);
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

void	path_valid(t_map *mat, int i, int j, int *path)
{
	if (i < 0 || j < 0 || i >= mat->rc[0] || j >= mat->rc[1]
		|| mat->mat[i][j] == 1)
		return ;
	if (mat->mat[i][j] == E)
	{
		path[0] = 1;
		return ;
	}
	mat->mat[i][j] = 1;
	path_valid(mat, i - 1, j, path);
	path_valid(mat, i + 1, j, path);
	path_valid(mat, i, j - 1, path);
	path_valid(mat, i, j + 1, path);
}
