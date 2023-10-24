/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:48:11 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/24 16:18:00 by zvakil           ###   ########.fr       */
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

void enemies_rend(t_vars *vars, t_enem_info *enemy)
{
	animation *temp;

	// if (enemy->dir == 1)
		temp = vars->enemies->right_anim;
	// else 
	// temp = vars->enemies->left_anim;
	mlx_put_image_to_window(vars->mlx, vars->win, temp->img, enemy->x, enemy->y);
}

void	main_display(t_vars *vars)
{
	t_enem_info *temp;
	
	temp = NULL;
	temp = vars->enemies;
	wall_set(vars);
	food_rend(vars);
	while(temp)
	{
		enemies_rend(vars, temp);
		temp = temp->next;
	}
	
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

animation	*image(animation *sprite, int frame)
{
	static int	i;
	animation	*temp;

	temp = sprite;
	if (i >= frame - 1)
		i = 0;
	else
		i++;
	return (image_helper(i, temp));
}
