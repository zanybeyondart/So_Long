/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 06:35:58 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/25 17:46:12 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

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
