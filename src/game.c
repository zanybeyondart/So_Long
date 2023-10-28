/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:42:55 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/28 14:02:49 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	quit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_vars(vars);
	exit(1);
}

int	events(int keycode, t_vars *vars)
{
	if (keycode == 53)
		quit(vars);
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		update_pos(keycode, vars->p1, vars);
	return (0);
}

int	callbacks(t_vars *vars)
{
	game_checks(vars);
	mlx_clear_window(vars->mlx, vars->win);
	main_display(vars);
	if (vars->exit->exit == 0)
		vars->exit->active = vars->exit->disabled;
	else
		vars->exit->active = vars->exit->enabled;
	if (vars->p1->move == 0)
		vars->p1->active = vars->p1->idle;
	else
		vars->p1->active = vars->p1->run;
	d_anim_helper(vars, vars->exit->active->img, vars->exit->x, vars->exit->y);
	d_anim_helper(vars, vars->p1->active->img, vars->p1->x, vars->p1->y);
	mlx_do_sync(vars->mlx);
	if (vars->end == 1)
		quit(vars);
	return (0);
}

int	on_release(int keycode, t_vars *vars)
{
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		vars->p1->move = 0;
	return (0);
}

int	game_start(int **mat, int *rc)
{
	t_vars	*vars;

	vars = NULL;
	vars = malloc(sizeof(t_vars));
	if (vars == NULL)
		malloc_er(vars, mat, rc);
	vars->end = 0;
	vars->map = NULL;
	vars->map = malloc(sizeof(t_map));
	if (vars->map == NULL)
		malloc_er(vars, mat, rc);
	vars->map->mat = mat;
	vars->map->rc = rc;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, rc[1] * 60, rc[0] * 60, "HELLO");
	nuller(vars);
	loadplayers(vars);
	mlx_loop_hook(vars->mlx, callbacks, vars);
	mlx_hook(vars->win, 2, 0, events, vars);
	mlx_hook(vars->win, 3, 0, on_release, vars);
	mlx_hook(vars->win, 17, 0, quit, vars);
	mlx_loop(vars->mlx);
	return (0);
}
