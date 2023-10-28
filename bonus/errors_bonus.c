/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:00:35 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/28 15:51:20 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	check_errors(int *rc, int **mat)
{
	if (rc[0] != 5 || rc[1] != 18)
	{
		printf("Map should be 18 X 5 !\n");
		matrix_free(mat, rc[0]);
		exit(1);
	}
	if (!check_matrix(mat, rc[0], rc[1]))
	{
		matrix_free(mat, rc[0]);
		exit(1);
	}
}

void	malloc_er(t_vars *vars, int **mat, int *rc)
{
	printf("Not enough memory to Malloc\n");
	if (mat)
		matrix_free(mat, rc[0]);
	free_vars(vars);
	exit(1);
}
