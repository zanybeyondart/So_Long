/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 06:35:58 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/21 15:12:29 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	load_exit0(t_vars *vars, animation *food)
{
	static int	i;
	char		*path;

	path = NULL;
	while (i != -1)
	{
		path = pather("./textures/exit/exit0/exit", i, ".xpm", path);
		if (path == NULL)
			i = -1;
		else
		{
			add_frames (vars, path, food);
			i++;
		}
	}
}

void	load_exit1(t_vars *vars, animation *food)
{
	static int	i;
	char		*path;

	path = NULL;
	while (i != -1)
	{
		path = pather("./textures/exit/exit1/exit", i, ".xpm", path);
		if (path == NULL)
			i = -1;
		else
		{
			add_frames (vars, path, food);
			i++;
		}
	}
}

animation	*exit_img(t_vars *vars)
{
	if (vars->exit->exit == 0)
		return (image(vars->exit->disabled));
	else
		return (image(vars->exit->enabled));
}

box	exit_bound(t_vars *vars, int key, int i, int j)
{
	box	temp;

	if (key == A || key == D)
	{
		temp.m_min = j * vars->wall->w;
		temp.m_max = temp.m_min + vars->exit->enabled->w;
		temp.m_bd = vars->p1->run->h;
		temp.min = i * vars->wall->h;
		temp.max = temp.min + vars->exit->enabled->h;
		temp.bd = vars->p1->run->w;
	}
	if (key == W || key == S)
	{
		temp.m_min = i * vars->wall->h;
		temp.m_max = temp.m_min + vars->exit->enabled->h;
		temp.m_bd = vars->p1->run->h;
		temp.min = j * vars->wall->w;
		temp.max = temp.min + vars->exit->enabled->w;
		temp.bd = vars->p1->run->w;
	}
	return (temp);
}

void	free_portal(portal *p, t_vars *vars)
{
	if (p)
	{
		free_animation(p->disabled, vars);
		free_animation(p->enabled, vars);
		free(p);
	}
}
