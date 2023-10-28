/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_rend_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:46:05 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/28 14:11:22 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

t_animation	*pow_image_helper(int frame, t_animation *temp)
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

t_animation	*pow_image(t_animation *sprite, int frame)
{
	static int	i;
	t_animation	*temp;

	temp = sprite;
	if (i >= frame - 1)
		i = 0;
	else
		i++;
	return (pow_image_helper(i, temp));
}

void	power_rend(t_vars *vars)
{
	t_animation	*temp2;

	temp2 = NULL;
	temp2 = vars->power->anim;
	if (vars->power->spawn == 1)
	{
		temp2 = pow_image(vars->power->anim, vars->power->frames);
		mlx_put_image_to_window(vars->mlx, vars->win, temp2->img,
			vars->power->x, vars->power->y);
	}
	if (vars->power->spawn == -1)
	{
		temp2 = pow_image(vars->power->anim_l, vars->power->frames);
		mlx_put_image_to_window(vars->mlx, vars->win, temp2->img,
			vars->power->x, vars->power->y);
	}
}
