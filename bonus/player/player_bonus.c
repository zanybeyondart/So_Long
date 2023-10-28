/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:28:49 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/28 14:11:08 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

t_animation	*player_img(t_vars *vars)
{
	if (vars->p1->move == 0 && vars->p1->dir == 1)
		return (image(vars->p1->idle, vars->p1->idle_frames));
	else if (vars->p1->move == 1 && vars->p1->dir == 1)
		return (image(vars->p1->run, vars->p1->idle_frames));
	else if (vars->p1->move == 0 && vars->p1->dir == -1)
		return (image(vars->p1->idle_l, vars->p1->idle_frames));
	else
		return (image(vars->p1->run_l, vars->p1->idle_frames));
}
