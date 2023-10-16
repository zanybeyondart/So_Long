/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:08:58 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/16 18:40:25 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	lim(int a, int b, int c)
{
	if (a > b && a < c)
		return (1);
	return (0);
}

int	check_inter(box temp, int pv, int pc)
{
	if (lim(pv, temp.m_min, temp.m_max)
		|| lim(pv + temp.m_bd, temp.m_min, temp.m_max))
		if (lim(pc, temp.min, temp.max)
			|| lim(pc + temp.bd, temp.min, temp.max))
			return (1);
	return (0);
}

box	col_bound(t_vars *vars, int key, int i, int j)
{
	box	temp;

	if (key == A || key == D)
	{
		temp.m_min = j * vars->wall->w;
		temp.m_max = temp.m_min + vars->food->w;
		temp.m_bd = vars->p1->run->h;
		temp.min = i * vars->wall->h;
		temp.max = temp.min + vars->food->h;
		temp.bd = vars->p1->run->w;
	}
	if (key == W || key == S)
	{
		temp.m_min = i * vars->wall->h;
		temp.m_max = temp.m_min + vars->food->h;
		temp.m_bd = vars->p1->run->h;
		temp.min = j * vars->wall->w;
		temp.max = temp.min + vars->food->w;
		temp.bd = vars->p1->run->w;
	}
	return (temp);
}

box	exit_bound(t_vars *vars, int key, int i, int j)
{
	box	temp;

	if (key == A || key == D)
	{
		temp.m_min = j * vars->wall->w;
		temp.m_max = temp.m_min + vars->exit->enabled->w;
		temp.m_bd = vars->p1->run->h;
		temp.min = i * vars->wall->h;
		temp.max = temp.min + vars->exit->enabled->h;
		temp.bd = vars->p1->run->w;
	}
	if (key == W || key == S)
	{
		temp.m_min = i * vars->wall->h;
		temp.m_max = temp.m_min + vars->exit->enabled->h;
		temp.m_bd = vars->p1->run->h;
		temp.min = j * vars->wall->w;
		temp.max = temp.min + vars->exit->enabled->w;
		temp.bd = vars->p1->run->w;
	}
	return (temp);
}

int	pos_check_1(int pc, int pv, int key, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			if (vars->map->mat[i][j] == 1
				&& check_inter(wall_bound (vars, key, i , j), pv, pc))
				return (0);
			if (vars->map->mat[i][j] == C
				&& check_inter(col_bound (vars, key, i , j), pv, pc))
				vars->map->mat[i][j] = -90;
			if (vars->map->mat[i][j] == E
				&& check_inter(col_bound (vars, key, i , j), pv, pc)
				&& vars->exit->exit == 1)
				quit(vars);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}


void	update_pos(int keycode, player *p1, t_vars *vars)
{
	if (keycode == W)
	{
		if (pos_check_1(p1->x, p1->y - SPEED, keycode, vars))
			p1->y -= SPEED;
	}
	else if (keycode == S)
	{
		if (pos_check_1(p1->x, p1->y + SPEED, keycode, vars))
			p1->y += SPEED;
	}
	else if (keycode == A)
	{
		if (pos_check_1(p1->y, p1->x - SPEED, keycode, vars))
			p1->x -= SPEED;
	}
	else if (keycode == D)
	{
		if (pos_check_1(p1->y, p1->x + SPEED, keycode, vars))
			p1->x += SPEED;
	}
	p1->move = 1;
}
