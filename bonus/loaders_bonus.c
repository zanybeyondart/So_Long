/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaders_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:03:12 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/24 15:30:07 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	load_wall(t_vars *vars)
{
	vars->wall = malloc (sizeof(animation));
	if (vars->wall == NULL)
		malloc_er(vars, NULL, NULL);
	vars->wall->img = NULL;
	vars->wall->next = NULL;
	list_wall(vars, vars->wall);
}

void	load_base(t_vars *vars)
{
	vars->base = malloc(sizeof(animation));
	if (vars->base == NULL)
		malloc_er(vars, NULL, NULL);
	vars->base->img = mlx_xpm_file_to_image(vars->mlx,
				"./textures/Walls/PNG/base.xpm",
				&vars->base->w, &vars->base->h);
	vars->base->next = NULL;
}

void	load_exit(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
	vars->exit->exit = 0;
	vars->exit->enabled = NULL;
	vars->exit->disabled = NULL;
}

void	load_exit_en_dis(t_vars *vars)
{
	vars->exit->disabled = malloc(sizeof(animation));
	if (vars->exit->disabled == NULL)
		malloc_er(vars, NULL, NULL);
	vars->exit->disabled->img = NULL;
	vars->exit->disabled->next = NULL;
	load_exit0(vars, vars->exit->disabled);
	vars->exit->enabled = malloc(sizeof(animation));
	if (vars->exit->enabled == NULL)
		malloc_er(vars, NULL, NULL);
	vars->exit->enabled->img = NULL;
	vars->exit->enabled->next = NULL;
	load_exit1(vars, vars->exit->enabled);
}

int	loadplayers(t_vars *vars)
{
	load_base(vars);
	load_wall(vars);
	load_p1(vars);
	load_exit(vars);
	load_p1_anims(vars);
	load_enemy(vars);
	load_enemy_anims(vars);
	vars->food = malloc(sizeof(animation));
	if (vars->food == NULL)
		malloc_er(vars, NULL, NULL);
	vars->food->img = NULL;
	vars->food->next = NULL;
	load_food(vars, vars->food);
	load_exit_en_dis(vars);
	return (0);
}
