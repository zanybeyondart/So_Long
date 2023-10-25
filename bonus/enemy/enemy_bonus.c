/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:17:16 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/25 16:25:42 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	enemy_wall_col(t_vars *vars, int i, int j, int dir)
{
	if (dir == 1)
	{
		while (vars->map->mat[i][j] != 1)
			j++;
		return (j * vars->wall->w);
	}
	else
	{
		while (vars->map->mat[i][j] != 1)
			j--;
		return ((j * vars->wall->w) + vars->wall->w);
	}
}

int	en_check_inter(box temp, int pv, int pc)
{
	if (lim(pv, temp.m_min, temp.m_max)
		|| lim(pv + temp.m_bd, temp.m_min, temp.m_max))
		if (lim(pc, temp.min, temp.max)
			|| lim(pc + temp.bd, temp.min, temp.max))
			return (1);
	return (0);
}

box	en_bound(t_vars *vars, t_enem_info *enemy)
{
	box	temp;

	temp.m_min = enemy->x;
	temp.m_max = temp.m_min + vars->enemies->right_anim->w;
	temp.m_bd = vars->enemies->right_anim->h;
	temp.min = enemy->y;
	temp.max = temp.min + vars->enemies->right_anim->h;
	temp.bd = vars->p1->run->w;
	return (temp);
}

void	enemy_updates(t_enem_info *enemy, t_vars *vars)
{
	if (enemy)
	{
		enemy_updates(enemy->next, vars);
		if (en_check_inter(en_bound(vars, enemy), vars->p1->x, vars->p1->y)
			&& enemy->alive == 0)
			quit(vars);
		if (enemy->x + (15 * enemy->dir) < enemy->l_wall
			|| (enemy->x + vars->enemies->right_anim->w)
			+ (15 * enemy->dir) > enemy->r_wall)
			enemy->dir *= -1;
		if (en_check_inter(en_bound(vars, enemy),
				vars->power->x, vars->power->y) && enemy->alive == 0)
		{
			vars->power->spawn = 0;
			vars->power->x = 0;
			vars->power->y = 0;
			enemy->alive = 1;
			vars->kill->spawn = 1;
			vars->kill->x = enemy->x;
			vars->kill->y = enemy->y;
		}
		enemy->x += 15 * enemy->dir;
	}
}