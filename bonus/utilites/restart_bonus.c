/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restart_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:34:53 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/28 14:11:30 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

void	restart_enemy_list(t_vars *vars, t_enem_info *temp, int i, int j)
{
	temp->x = j * vars->wall->w + 10;
	temp->y = i * vars->wall->h + 10;
	temp->dir = 1;
	temp->alive = 0;
	temp->active = NULL;
}

void	reset_pec(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
			if (vars->map->mat[i][j] == -90)
				vars->map->mat[i][j] = C;
			j++;
		}
		j = 0;
		i++;
	}
	vars->exit->exit = 0;
}

void	restart_enemy(t_vars *vars)
{
	t_enem_info	*temp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	temp = vars->enemies;
	while (i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			if (vars->map->mat[i][j] == V && temp)
			{
				restart_enemy_list(vars, temp, i, j);
				temp = temp->next;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	restart_game(t_vars *vars)
{
	reset_pec(vars);
	restart_enemy(vars);
	vars->power->spawn = 0;
	vars->power->x = 0;
	vars->power->y = 0;
	vars->game_state = 2;
}
