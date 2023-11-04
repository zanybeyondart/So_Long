/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:08:03 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/04 17:03:57 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	list_food(t_vars *vars, t_animation *food)
{
	static int	i;
	char		*path;

	path = NULL;
	while (i != -1)
	{
		path = pather("./textures_bonus/food/", i, ".xpm", path);
		if (path == NULL)
			i = -1;
		else
		{
			add_frames (vars, path, food);
			i++;
		}
	}
}

void	load_food(t_vars *vars)
{
	vars->food = malloc(sizeof(t_animation));
	if (vars->food == NULL)
		malloc_er(vars, NULL, NULL);
	vars->food->img = NULL;
	vars->food->next = NULL;
	list_food(vars, vars->food);
}

void	food_rend(t_vars *vars)
{
	int			i;
	int			j;
	t_animation	*temp;

	i = 0;
	j = 0;
	temp = vars->food;
	while (i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			if (vars->map->mat[i][j] == C)
				mlx_put_image_to_window(vars->mlx, vars->win, temp->img,
					j * vars->wall->w + 10, i * vars->wall->h + 10);
			if (temp->next)
				temp = temp->next;
			else
				temp = vars->food;
			j++;
		}
		j = 0;
		i++;
	}
}

t_box	col_bound(t_vars *vars, int key, int i, int j)
{
	t_box	temp;

	if (key == A || key == D)
	{
		temp.m_min = j * vars->wall->w;
		temp.m_max = temp.m_min + vars->food->w;
		temp.m_bd = vars->p1->run->h;
		temp.min = i * vars->wall->h;
		temp.max = temp.min + vars->food->h;
		temp.bd = vars->p1->run->w;
	}
	if (key == W || key == S)
	{
		temp.m_min = i * vars->wall->h;
		temp.m_max = temp.m_min + vars->food->h;
		temp.m_bd = vars->p1->run->h;
		temp.min = j * vars->wall->w;
		temp.max = temp.min + vars->food->w;
		temp.bd = vars->p1->run->w;
	}
	return (temp);
}
