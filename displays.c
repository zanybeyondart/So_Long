/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:48:11 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/18 17:45:38 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	main_display(t_vars *vars)
{
	wall_set(vars);
	food_rend(vars);
}

void	d_anim_helper(t_vars *vars, void *img, int x, int y)
{
	static int	i;

	i = 0;
	if (i % 25 == 0 && vars->p1->move == 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
	}
	if (i % 8 == 0 && vars->p1->move == 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
	}
	i++;
	if (i > 1000000)
		i = 0;
}

animation	*image_helper(int frame, animation *temp)
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

animation	*image(t_vars *vars, animation *sprite)
{
	static int	i;
	int			j;
	animation	*temp;

	j = 0;
	temp = sprite;
	while (temp)
	{
		temp = temp->next;
		j++;
	}
	temp = sprite;
	if (i >= j - 1)
		i = 0;
	else
		i++;
	return (image_helper(i, temp));
}
