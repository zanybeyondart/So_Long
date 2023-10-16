/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:48:11 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/15 14:56:58 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void main_display(t_vars *vars)
{
	wall_set(vars);
	food_rend(vars);
}

void	food_rend(t_vars *vars)
{
	int			i;
	int			j;
	animation	*temp;

	i = 0;
	j = 0;
	temp = vars->food;
	while(i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			if (vars->map->mat[i][j] == C)
				mlx_put_image_to_window(vars->mlx, vars->win, temp->img, j * vars->wall->w + 10, i * vars->wall->h + 10);
			if (temp->next && vars->map->mat[i][j] == -90)
				temp = temp->next;
			else if (temp->next)
				temp = temp->next;
			else
				temp = vars->food;
			j++;
		}
		j = 0;
		i++;
	}
}

void	wall_rend(t_vars *vars, int x, int y, int index)
{
	int i;
	animation *temp;

	i = 0;
	temp = vars->wall;
	while (i++ < index)
	temp = temp->next;
	mlx_put_image_to_window(vars->mlx, vars->win, temp->img, x, y);
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

// void d_anim(t_vars *vars, animation *sprite)
// {
// 	while (sprite)
// 	{
// 		mlx_clear_window(vars->mlx, vars->win);
// 		main_display(vars);
// 		d_anim_helper(vars, sprite);
// 		mlx_do_sync(vars->mlx);
// 		sprite = sprite->next;
// 	}
// }

