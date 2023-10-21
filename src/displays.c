/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:48:11 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/21 15:10:40 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	base_rend(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->base->img,
				j * vars->wall->w, i * vars->wall->h);
			j++;
		}
		j = 0;
		i++;
	}
}

void	main_display(t_vars *vars)
{
	base_rend(vars);
	wall_set(vars);
	food_rend(vars);
}

void	d_anim_helper(t_vars *vars, void *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
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

animation	*image(animation *sprite)
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
