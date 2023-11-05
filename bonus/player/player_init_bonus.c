/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:48:14 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/05 05:54:05 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

void	p1_nulls(t_vars *vars)
{
	vars->p1->idle = NULL;
	vars->p1->idle_l = NULL;
	vars->p1->run = NULL;
	vars->p1->run_l = NULL;
	vars->p1->death_l = NULL;
	vars->p1->death_r = NULL;
	vars->p1->win_r = NULL;
	vars->p1->win_l = NULL;
	vars->p1->dir = 1;
	vars->p1->move = 0;
	vars->p1->move_count = 0;
}

void	load_p1(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	vars->p1 = malloc(sizeof(t_player));
	if (vars->p1 == NULL)
		malloc_er(vars, NULL, NULL);
	vars->p1->move_count = 0;
	vars->p1->dir = 1;
	vars->p1->move = 0;
	while (i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			if (vars->map->mat[i][j] == P)
			{
				vars->p1->x = j * vars->wall->w + 10;
				vars->p1->y = i * vars->wall->h + 10;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	load_p1_anims_idle_assign(t_vars *vars)
{
	vars->p1->idle = malloc(sizeof(t_animation));
	if (vars->p1->idle == NULL)
		malloc_er(vars, NULL, NULL);
	vars->p1->idle->img = NULL;
	vars->p1->idle->next = NULL;
	load_anim_idle(vars, vars->p1->idle);
	vars->p1->idle_l = malloc(sizeof(t_animation));
	if (vars->p1->idle_l == NULL)
		malloc_er(vars, NULL, NULL);
	vars->p1->idle_l->img = NULL;
	vars->p1->idle_l->next = NULL;
	load_anim_idle_2(vars, vars->p1->idle_l);
}

void	load_p1_anims_run_assign(t_vars *vars)
{
	vars->p1->run = malloc(sizeof(t_animation));
	if (vars->p1->run == NULL)
		malloc_er(vars, NULL, NULL);
	vars->p1->run->img = NULL;
	vars->p1->run->next = NULL;
	load_anim_run(vars, vars->p1->run);
	vars->p1->run_l = malloc(sizeof(t_animation));
	if (vars->p1->run_l == NULL)
		malloc_er(vars, NULL, NULL);
	vars->p1->run_l->img = NULL;
	vars->p1->run_l->next = NULL;
	load_anim_run_2(vars, vars->p1->run_l);
}
