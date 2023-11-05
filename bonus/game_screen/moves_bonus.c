/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 07:11:20 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/05 09:02:50 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

t_animation	*number(t_vars *vars, int pos)
{
	t_animation	*temp;
	int			i;
	int			moves;

	i = 0;
	moves = vars->p1->move_count;
	temp = vars->number;
	while ((pos == 0 || pos == 1) && moves >= 100)
		moves -= 100;
	if (pos == 0)
	{
		while (i++ < moves / 10)
			temp = temp->next;
	}
	else if (pos == 1)
	{
		while (i++ < moves % 10)
			temp = temp->next;
	}
	else if (pos == 2 && moves >= 100)
	{
		while (i++ < moves / 100)
			temp = temp->next;
	}
	return (temp);
}

void	moves_rend(t_vars *vars)
{
	t_animation	*first;
	t_animation	*second;
	t_animation	*third;

	first = number(vars, 0);
	second = number(vars, 1);
	third = number(vars, 2);
	mlx_put_image_to_window(vars->mlx, vars->win, first->img,
		(vars->map->rc[1] / 2) * 60 - (vars->number->w / 2),
		vars->map->rc[0] * 60 + 10);
	mlx_put_image_to_window(vars->mlx, vars->win, second->img,
		(vars->map->rc[1] / 2) * 60 + (vars->number->w / 2),
		vars->map->rc[0] * 60 + 10);
	mlx_put_image_to_window(vars->mlx, vars->win, third->img,
		(vars->map->rc[1] / 2) * 60 - 3 *(vars->number->w / 2),
		vars->map->rc[0] * 60 + 10);
}

void	load_numbers(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures_bonus/numbers/", i, ".xpm", path);
		if (path == NULL)
			break ;
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}

void	moves_loader(t_vars *vars)
{
	vars->number = malloc(sizeof(t_animation));
	if (!vars->number)
		malloc_er(vars, NULL, NULL);
	vars->number->img = NULL;
	vars->number->next = NULL;
	load_numbers(vars, vars->number);
}
