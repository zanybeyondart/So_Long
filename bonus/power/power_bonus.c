/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:24:42 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/28 14:11:19 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

int	power_check_inter(t_box temp, int pv, int pc, t_vars *vars)
{
	if (lim(pv, temp.m_min, temp.m_max)
		|| lim(pv + temp.m_bd, temp.m_min, temp.m_max))
	{
		if (lim(pc, temp.min, temp.max)
			|| lim(pc + temp.bd, temp.min, temp.max))
		{
			vars->power->spawn = 0;
			vars->power->x = 0;
			vars->power->y = 0;
		}
	}
	return (1);
}

t_box	power_bound(t_vars *vars, int i, int j)
{
	t_box	temp;

	temp.m_min = i * vars->wall->h;
	temp.m_max = temp.m_min + vars->wall->h;
	temp.m_bd = vars->power->anim->h;
	temp.min = j * vars->wall->w;
	temp.max = temp.min + vars->wall->w;
	temp.bd = vars->power->anim->w;
	return (temp);
}

void	power_updates(t_vars *vars)
{
	vars->power->x += (25 * vars->power->spawn);
}

void	power_check(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map->rc[0])
	{
		j = 0;
		while (j < vars->map->rc[1])
		{
			if (vars->map->mat[i][j] == 1)
				power_check_inter(power_bound(vars, i, j),
					vars->power->y, vars->power->x, vars);
			j++;
		}
		i++;
	}
}
