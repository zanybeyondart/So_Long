/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaders_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:03:12 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/05 05:35:48 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	load_wall(t_vars *vars)
{
	vars->wall = malloc (sizeof(t_animation));
	if (vars->wall == NULL)
		malloc_er(vars, NULL, NULL);
	vars->wall->img = NULL;
	vars->wall->next = NULL;
	list_wall(vars, vars->wall);
}

void	load_base(t_vars *vars)
{
	vars->base = malloc(sizeof(t_animation));
	if (vars->base == NULL)
		malloc_er(vars, NULL, NULL);
	vars->base->img = mlx_xpm_file_to_image(vars->mlx,
			"./textures_bonus/base.xpm",
			&vars->base->w, &vars->base->h);
	vars->base->next = NULL;
}

int	loadplayers(t_vars *vars)
{
	nuller(vars);
	load_base(vars);
	load_wall(vars);
	load_p1(vars);
	load_p1_anims_idle_assign(vars);
	load_p1_anims_run_assign(vars);
	load_p1_anims_death_assign(vars);
	load_p1_anims_win_assign(vars);
	load_exit(vars);
	load_exit_en_dis(vars);
	load_enemies(vars);
	load_enemy_anims(vars);
	load_food(vars);
	load_power(vars);
	load_kill(vars);
	moves_loader(vars);
	load_screen_1(vars);
	load_screen_3(vars);
	load_screen_4(vars);
	load_screen_5(vars);
	load_screen_6(vars);
	return (0);
}
