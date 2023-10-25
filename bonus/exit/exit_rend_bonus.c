/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_rend_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:17:24 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/25 17:26:07 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

animation	*exit_image_helper(int frame, animation *temp)
{
	int	i;

	i = 0;
	while (i < frame)
	{
		temp = temp->next;
		i++;
	}
	return (temp);
}

animation	*exit_image(animation *sprite, int frame)
{
	static int	i;
	animation	*temp;

	temp = sprite;
	if (i >= frame - 1)
		i = 0;
	else
		i++;
	return (exit_image_helper(i, temp));
}

animation	*exit_img(t_vars *vars)
{
	if (vars->exit->exit == 0)
		return (exit_image(vars->exit->disabled, vars->exit->exit_dis_frame));
	else
		return (exit_image(vars->exit->enabled, vars->exit->exit_en_frame));
}

void	exit_rend(t_vars *vars)
{
	vars->exit->active = exit_img(vars);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->exit->active->img, vars->exit->x, vars->exit->y);
}