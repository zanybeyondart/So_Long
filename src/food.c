/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:08:03 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/18 17:33:31 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	load_food(t_vars *vars, animation *food)
{
	static int	i;
	char		*path;

	path = NULL;
	while (i != -1)
	{
		path = pather("./textures/food/food", i, ".xpm", path);
		if (path == NULL)
			i = -1;
		else
		{
			add_frames (vars, path, food);
			i++;
		}
	}
}

void	food_rend(t_vars *vars)
{
	int			i;
	int			j;
	animation	*temp;

	i = 0;
	j = 0;
	temp = vars->food;
	while (i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			if (vars->map->mat[i][j] == C)
				mlx_put_image_to_window(vars->mlx, vars->win, temp->img,
					j * vars->wall->w + 10, i * vars->wall->h + 10);
			if (temp->next && vars->map->mat[i][j] == -90)
				temp = temp->next;
			else if (temp->next)
				temp = temp->next;
			else
				temp = vars->food;
			j++;
		}
		j = 0;
		i++;
	}
}

box	col_bound(t_vars *vars, int key, int i, int j)
{
	box	temp;

	if (key == A || key == D)
	{
		temp.m_min = j * vars->wall->w;
		temp.m_max = temp.m_min + vars->food->w;
		temp.m_bd = vars->p1->run->h;
		temp.min = i * vars->wall->h;
		temp.max = temp.min + vars->food->h;
		temp.bd = vars->p1->run->w;
	}
	if (key == W || key == S)
	{
		temp.m_min = i * vars->wall->h;
		temp.m_max = temp.m_min + vars->food->h;
		temp.m_bd = vars->p1->run->h;
		temp.min = j * vars->wall->w;
		temp.max = temp.min + vars->food->w;
		temp.bd = vars->p1->run->w;
	}
	return (temp);
}
