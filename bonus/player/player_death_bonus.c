/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_death_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:03:09 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/04 16:33:49 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

int	death_rend(t_vars *vars, t_animation *temp, int x, int y)
{
	if (temp)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->base->img, 0, 0);
		wall_set(vars);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->exit->active->img, vars->exit->x, vars->exit->y);
		food_rend(vars);
		moves_rend(vars);
		enemies_list_send(vars);
		if (vars->kill->spawn == 1)
			kill_rend(vars);
		power_rend(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, temp->img, x, y);
		mlx_do_sync(vars->mlx);
		usleep(100000);
		return (death_rend(vars, temp->next, x, y));
	}
	return (1);
}

void	death_seq(t_vars *vars)
{
	t_animation	*temp;

	if (vars->p1->dir == 1)
		temp = vars->p1->death_r;
	else
		temp = vars->p1->death_l;
	death_rend(vars, temp, vars->p1->x, vars->p1->y);
	death_rend(vars, temp, vars->p1->x, vars->p1->y);
	death_rend(vars, temp, vars->p1->x, vars->p1->y);
	death_rend(vars, temp, vars->p1->x, vars->p1->y);
	death_rend(vars, temp, vars->p1->x, vars->p1->y);
	vars->game_state = 5;
}

void	load_p1_anims_death_assign(t_vars *vars)
{
	vars->p1->death_r = malloc(sizeof(t_animation));
	if (vars->p1->death_r == NULL)
		malloc_er(vars, NULL, NULL);
	vars->p1->death_r->img = NULL;
	vars->p1->death_r->next = NULL;
	load_anim_death(vars, vars->p1->death_r);
	vars->p1->death_l = malloc(sizeof(t_animation));
	if (vars->p1->death_l == NULL)
		malloc_er(vars, NULL, NULL);
	vars->p1->death_l->img = NULL;
	vars->p1->death_l->next = NULL;
	load_anim_death_2(vars, vars->p1->death_l);
}

void	load_anim_death(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures_bonus/player/death_r/", i, ".xpm", path);
		if (path == NULL)
		{
			break ;
		}
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}

void	load_anim_death_2(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures_bonus/player/death_l/", i, ".xpm", path);
		if (path == NULL)
		{
			break ;
		}
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}
