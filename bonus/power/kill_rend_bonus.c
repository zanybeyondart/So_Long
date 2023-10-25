/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_rend_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:55:49 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/25 16:57:21 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"



animation	*kill_image_helper(int frame, animation *temp)
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

animation	*kill_image(animation *sprite, int frame, t_vars *vars)
{
	static int	i;
	animation	*temp;

	temp = sprite;
	if (i >= frame - 1)
	{
		vars->kill->spawn = 0;
		i = 0;
		return (kill_image_helper(frame - 1, temp));
	}
	else
		i++;
	return (kill_image_helper(i, temp));
}

void	kill_rend(t_vars *vars)
{
	animation	*temp;

	temp = kill_image(vars->kill->anim, vars->kill->frames, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, temp->img,
		vars->kill->x, vars->kill->y);
}
