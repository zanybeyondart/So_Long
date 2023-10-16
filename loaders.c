/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:03:12 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/15 15:00:45 by zvakil           ###   ########.fr       */
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

void	load_anim_idle(t_vars *vars, animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (i != -1)
	{
		path = pather("./textures/Idle/PNG/idle", i, ".xpm", path);
		if (path == NULL)
			i = -1;
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}

void	load_anim_run(t_vars *vars, animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (i != -1)
	{
		path = pather("./textures/run/PNG/run", i, ".xpm", path);
		if (path == NULL)
			i = -1;
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}

int	loadplayers(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!vars->wall)
	{
		vars->wall = malloc (sizeof(animation));
		list_wall(vars, vars->wall);
	}
	if (!vars->p1)
	{
		vars->p1 = malloc(sizeof(player));
		while (i < vars->map->rc[0])
		{
			while (j < vars->map->rc[1])
			{
				if (vars->map->mat[i][j] == P)
				{
					vars->p1->x = j * vars->wall->w;
					vars->p1->y = i * vars->wall->h;
				}
				j++;
			}
			j = 0;
			i++;
		}
		i = 0;
		j = 0;
	}
	if (!vars->p1->idle)
	{
		vars->p1->idle = malloc(sizeof(animation));
		load_anim_idle(vars, vars->p1->idle);
	}
	if (!vars->p1->run)
	{
		vars->p1->run = malloc(sizeof(animation));
		load_anim_run(vars, vars->p1->run);
	}
	if (!vars->food)
	{
		vars->food = malloc(sizeof(animation));
		load_food(vars, vars->food);
	}
	if (!vars->exit)
	{
		vars->exit = malloc(sizeof(portal));
		while (i < vars->map->rc[0])
		{
			while (j < vars->map->rc[1])
			{
				if (vars->map->mat[i][j] == E)
				{
					vars->exit->x = j * vars->wall->w;
					vars->exit->y = i * vars->wall->h;
				}
				j++;
			}
			j = 0;
			i++;
		}
	}
	if (!vars->exit->disabled)
	{
		vars->exit->disabled = malloc(sizeof(animation));
		load_exit0(vars, vars->exit->disabled);
	}
	if (!vars->exit->enabled)
	{
		vars->exit->enabled = malloc(sizeof(animation));
		load_exit1(vars, vars->exit->enabled);
	}
	return (0);
}

