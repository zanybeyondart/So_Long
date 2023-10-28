/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:08:09 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/28 14:05:23 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	wall_set_2(t_vars *vars, int i, int j)
{
	if ((i == 0 && j == 0) || (i == 0 && j == vars->map->rc[1] - 1)
		|| (i == vars->map->rc[0] - 1 && j == 0)
		|| (i == vars->map->rc[0] - 1 && j == vars->map->rc[1] - 1))
	{
		wall_rend(vars, j * vars->wall->w, i * vars->wall->h, 0);
	}
	else if (i != 0 && i != vars->map->rc[0] - 1
		&& (j == 0 || j == vars->map->rc[1] - 1))
	{
		wall_rend(vars, j * vars->wall->w, i * vars->wall->h, 2);
	}
	else if ((i == 0 || i == vars->map->rc[0] - 1)
		&& (j != 0 || j != vars->map->rc[1] - 1))
	{
		wall_rend(vars, j * vars->wall->w, i * vars->wall->h, 1);
	}
	else
		wall_rend(vars, j * vars->wall->w, i * vars->wall->h, 3);
}

void	wall_set(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			if (vars->map->mat[i][j] == 1)
				wall_set_2(vars, i, j);
			else
				mlx_put_image_to_window(vars->mlx, vars->win, vars->base->img,
					j * vars->wall->w, i * vars->wall->h);
			j++;
		}
		j = 0;
		i++;
	}
}

t_box	wall_bound(t_vars *vars, int key, int i, int j)
{
	t_box	temp;

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

void	list_wall(t_vars *vars, t_animation *wall)
{
	static int	i;
	char		*path;

	path = NULL;
	while (i != -1)
	{
		path = pather("./textures/Walls/wall", i, ".xpm", path);
		if (path == NULL)
			i = -1;
		else
		{
			add_frames (vars, path, wall);
			i++;
		}
	}
}

void	wall_rend(t_vars *vars, int x, int y, int index)
{
	int			i;
	t_animation	*temp;

	i = 0;
	temp = vars->wall;
	while (i++ < index)
		temp = temp->next;
	mlx_put_image_to_window(vars->mlx, vars->win, temp->img, x, y);
}
