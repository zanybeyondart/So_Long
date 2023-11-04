/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:11:25 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/04 16:56:39 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

void	load_exit(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	vars->exit = malloc(sizeof(t_portal));
	if (vars->exit == NULL)
		malloc_er(vars, NULL, NULL);
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
	vars->exit->exit = 0;
	vars->exit->enabled = NULL;
	vars->exit->disabled = NULL;
}

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

void	load_exit_en_dis(t_vars *vars)
{
	vars->exit->disabled = malloc(sizeof(t_animation));
	if (vars->exit->disabled == NULL)
		malloc_er(vars, NULL, NULL);
	vars->exit->disabled->img = NULL;
	vars->exit->disabled->next = NULL;
	load_exit0(vars, vars->exit->disabled);
	vars->exit->enabled = malloc(sizeof(t_animation));
	if (vars->exit->enabled == NULL)
		malloc_er(vars, NULL, NULL);
	vars->exit->enabled->img = NULL;
	vars->exit->enabled->next = NULL;
	load_exit1(vars, vars->exit->enabled);
}
