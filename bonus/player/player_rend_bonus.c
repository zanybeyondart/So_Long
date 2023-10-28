/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rend_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:24:13 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/28 14:11:13 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

void	player_rend(t_vars *vars)
{
	vars->p1->active = player_img(vars);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->p1->active->img, vars->p1->x, vars->p1->y);
}
