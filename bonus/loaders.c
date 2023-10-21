/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:03:12 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/20 22:10:36 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	load_wall(t_vars *vars)
{
	vars->wall = NULL;
	vars->wall = malloc (sizeof(animation));
	if (vars->wall == NULL)
		malloc_er(vars, NULL, NULL);
	list_wall(vars, vars->wall);
}

void	load_base(t_vars *vars)
{
	vars->base = NULL;
	vars->base = malloc(sizeof(animation));
	if (vars->base == NULL)
		malloc_er(vars, NULL, NULL);
	if (!vars->base->img)
		vars->base->img = mlx_xpm_file_to_image(vars->mlx,
				"./textures/Walls/PNG/base.xpm",
				&vars->base->w, &vars->base->h);
}

void	load_exit(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	vars->exit = NULL;
	vars->exit = malloc(sizeof(portal));
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
}

void	load_exit_en_dis(t_vars *vars)
{
	vars->exit->disabled = NULL;
	vars->exit->disabled = malloc(sizeof(animation));
	if (vars->exit->disabled == NULL)
		malloc_er(vars, NULL, NULL);
	load_exit0(vars, vars->exit->disabled);
	vars->exit->enabled = NULL;
	vars->exit->enabled = malloc(sizeof(animation));
	if (vars->exit->enabled == NULL)
		malloc_er(vars, NULL, NULL);
	load_exit1(vars, vars->exit->enabled);
}

int	loadplayers(t_vars *vars)
{
	if (!vars->base)
		load_base(vars);
	if (!vars->wall)
		load_wall(vars);
	if (!vars->p1)
		load_p1(vars);
	if (!vars->exit)
		load_exit(vars);
	if (!vars->p1->idle && !vars->p1->run)
		load_p1_anims(vars);
	if (!vars->food)
	{
		vars->food = NULL;
		vars->food = malloc(sizeof(animation));
		if (vars->food == NULL)
			malloc_er(vars, NULL, NULL);
		load_food(vars, vars->food);
	}
	if (!vars->exit->enabled && !vars->exit->disabled)
		load_exit_en_dis(vars);
	return (0);
}
