/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:08:09 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/15 10:37:54 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	wall_set(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			if (vars->map->mat[i][j] == 1)
				if ((i == 0 && j == 0) || (i == 0 && j == vars->map->rc[1] - 1)
					|| (i == vars->map->rc[0] - 1 && j == 0)
					|| (i == vars->map->rc[0] - 1 && j == vars->map->rc[1] - 1))
					wall_rend(vars, j * vars->wall->w, i * vars->wall->h, 0);
				else if (i != 0 && i != vars->map->rc[0] - 1
					&& (j == 0 || j == vars->map->rc[1] - 1))
					wall_rend(vars, j * vars->wall->w, i * vars->wall->h, 2);
				else if (i == 0 || i == vars->map->rc[0] - 1
					&& (j != 0 || j != vars->map->rc[1] - 1))
					wall_rend(vars, j * vars->wall->w, i * vars->wall->h, 1);
				else
					wall_rend(vars, j * vars->wall->w, i * vars->wall->h, 3);
			j++;
		}
		j = 0;
		i++;
	}
}

box	wall_bound(t_vars *vars, int key, int i, int j)
{
	box	temp;

	if (key == A || key == D)
	{
		temp.m_min = j * vars->wall->w;
		temp.m_max = temp.m_min + vars->wall->w;
		temp.m_bd = vars->p1->run->h;
		temp.min = i * vars->wall->h;
		temp.max = temp.min + vars->wall->h;
		temp.bd = vars->p1->run->w;
	}
	if (key == W || key == S)
	{
		temp.m_min = i * vars->wall->h;
		temp.m_max = temp.m_min + vars->wall->h;
		temp.m_bd = vars->p1->run->h;
		temp.min = j * vars->wall->w;
		temp.max = temp.min + vars->wall->w;
		temp.bd = vars->p1->run->w;
	}
	return (temp);
}


void	list_wall(t_vars *vars, animation *wall)
{
	static int	i;
	char		*path;

	path = NULL;
	while (i != -1)
	{
		path = pather("./textures/Walls/PNG/wall", i, ".xpm", path);
		if (path == NULL)
			i = -1;
		else
		{
			add_frames (vars, path, wall);
			i++;
		}
	}
}