/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:48:11 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/04 14:52:27 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	main_display(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->base->img, 0, 0);
	wall_set(vars);
	exit_rend(vars);
	food_rend(vars);
	moves_rend(vars);
	enemies_list_send(vars);
	if (vars->kill->spawn == 1)
		kill_rend(vars);
	player_rend(vars);
	power_rend(vars);
}

t_animation	*image_helper(int frame, t_animation *temp)
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

t_animation	*image(t_animation *sprite, int frame)
{
	static int	i;
	t_animation	*temp;

	temp = sprite;
	if (i >= frame - 1)
		i = 0;
	else
		i++;
	return (image_helper(i, temp));
}
