/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 06:35:58 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/28 14:00:32 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	load_exit0(t_vars *vars, t_animation *food)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures/exit/exit0/exit", i, ".xpm", path);
		if (path == NULL)
		{
			vars->exit->exit_dis_frame = i;
			break ;
		}
		else
		{
			add_frames (vars, path, food);
			i++;
		}
	}
}

void	load_exit1(t_vars *vars, t_animation *food)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures/exit/exit1/exit", i, ".xpm", path);
		if (path == NULL)
		{
			vars->exit->exit_en_frame = i;
			break ;
		}
		else
		{
			add_frames (vars, path, food);
			i++;
		}
	}
}

t_animation	*exit_img(t_vars *vars)
{
	if (vars->exit->exit == 0)
		return (image(vars->exit->disabled, vars->exit->exit_dis_frame));
	else
		return (image(vars->exit->enabled, vars->exit->exit_en_frame));
}

t_box	exit_bound(t_vars *vars, int key, int i, int j)
{
	t_box	temp;

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

void	free_portal(t_portal *p, t_vars *vars)
{
	if (p)
	{
		free_animation(p->disabled, vars);
		free_animation(p->enabled, vars);
		free(p);
	}
}
