/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_win_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:03:09 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/27 12:05:12 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

int	win_rend(t_vars *vars, t_animation *temp, int x, int y)
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
		return (win_rend(vars, temp->next, x, y));
	}
	usleep(200000);
	return (1);
}

void	win_seq(t_vars *vars)
{
	t_animation	*temp;

	if (vars->p1->dir == 1)
		temp = vars->p1->win_r;
	else
		temp = vars->p1->win_l;
	win_rend(vars, temp, vars->exit->x + 10, vars->exit->y + 10);
	vars->game_state = 4;
}

void	load_anim_win(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures_bonus/player/win_r/", i, ".xpm", path);
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

void	load_anim_win_2(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures_bonus/player/win_l/", i, ".xpm", path);
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

void	load_p1_anims_win_assign(t_vars *vars)
{
	vars->p1->win_r = malloc(sizeof(t_animation));
	if (vars->p1->win_r == NULL)
		malloc_er(vars, NULL, NULL);
	vars->p1->win_r->img = NULL;
	vars->p1->win_r->next = NULL;
	load_anim_win(vars, vars->p1->win_r);
	vars->p1->win_l = malloc(sizeof(t_animation));
	if (vars->p1->win_l == NULL)
		malloc_er(vars, NULL, NULL);
	vars->p1->win_l->img = NULL;
	vars->p1->win_l->next = NULL;
	load_anim_win_2(vars, vars->p1->win_l);
}
