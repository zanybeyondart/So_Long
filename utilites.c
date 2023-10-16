/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:03:02 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/16 17:33:10 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

animation	*image_helper(int frame, animation *temp)
{
	int	i;

	i = 0;
	while (i < frame)
	{
		temp = temp->next;
		i++;
	}
	return (temp);
}

animation	*image(t_vars *vars, animation *sprite)
{
	static int	i;
	int			j;
	animation	*temp;

	j = 0;
	temp = sprite;
	while (temp)
	{
		temp = temp->next;
		j++;
	}
	temp = sprite;
	if (i >= j - 1)
		i = 0;
	else
		i++;
	return (image_helper(i, temp));
}

animation	*player_img(t_vars *vars)
{
	if (vars->p1->move == 0)
		return (image(vars, vars->p1->idle));
	else
		return (image(vars, vars->p1->run));
}

animation	*exit_img(t_vars *vars)
{
	if (vars->exit->exit == 0)
		return (image(vars, vars->exit->disabled));
	if (vars->exit->exit == 1)
		return (image(vars, vars->exit->enabled));
}

int	matrix_check(t_vars *vars, int i, int j)
{
	if (i == vars->map->rc[0] - 1 && j == vars->map->rc[1] - 1)
		return (vars->map->mat[i][j]);
	if (j == vars->map->rc[1] - 1)
		return (matrix_check(vars, i + 1, 0));
	return (matrix_check(vars, i, j + 1));
}

int	matrix_check_2(t_vars *vars, int i, int j)
{
	if (i == vars->map->rc[0] - 1 && j == vars->map->rc[1] - 1)
		return (vars->map->mat[i][j]);
	if (j == vars->map->rc[1] - 1)
		return (matrix_check(vars, i + 1, 0));
	return (matrix_check(vars, i, j + 1));
}