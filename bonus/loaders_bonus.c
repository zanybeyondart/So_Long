/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaders_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:03:12 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/25 18:03:57 by zvakil           ###   ########.fr       */
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

int	loadplayers(t_vars *vars)
{
	load_base(vars);
	load_wall(vars);
	load_p1(vars);
	load_p1_anims_idle_assign(vars);
	load_p1_anims_run_assign(vars);
	load_exit(vars);
	load_exit_en_dis(vars);
	load_enemies(vars);
	load_enemy_anims(vars);
	load_food(vars);
	load_power(vars);
	load_kill(vars);
	return (0);
}
