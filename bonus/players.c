/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:28:49 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/21 15:12:48 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	load_p1(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	vars->p1 = NULL;
	vars->p1 = malloc(sizeof(player));
	if (vars->p1 == NULL)
		malloc_er(vars, NULL, NULL);
	vars->p1->move_count = 0;
	while (i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			if (vars->map->mat[i][j] == P)
			{
				vars->p1->x = j * vars->wall->w;
				vars->p1->y = i * vars->wall->h;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	load_anim_idle(t_vars *vars, animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (i != -1)
	{
		path = pather("./textures/Player/Idle/PNG/idle", i, ".xpm", path);
		if (path == NULL)
			i = -1;
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}

void	load_anim_run(t_vars *vars, animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (i != -1)
	{
		path = pather("./textures/Player/run/PNG/run", i, ".xpm", path);
		if (path == NULL)
			i = -1;
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}

animation	*player_img(t_vars *vars)
{
	if (vars->p1->move == 0)
		return (image(vars->p1->idle));
	else
		return (image(vars->p1->run));
}

void	load_p1_anims(t_vars *vars)
{
	vars->p1->idle = NULL;
	vars->p1->idle = malloc(sizeof(animation));
	if (vars->p1->idle == NULL)
		malloc_er(vars, NULL, NULL);
	load_anim_idle(vars, vars->p1->idle);
	vars->p1->run = NULL;
	vars->p1->run = malloc(sizeof(animation));
	if (vars->p1->run == NULL)
		malloc_er(vars, NULL, NULL);
	load_anim_run(vars, vars->p1->run);
}
