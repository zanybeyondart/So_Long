/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:42:55 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/21 21:59:15 by zvakil           ###   ########.fr       */
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
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		update_pos(keycode, vars->p1, vars);
	return (0);
}

int	callbacks(t_vars *vars)
{
	// usleep(100000);
	game_checks(vars);
	loadplayers(vars);
	// vars->p1->active = player_img(vars);
	// vars->exit->active = exit_img(vars);
	mlx_clear_window(vars->mlx, vars->win);
	main_display(vars);
	d_anim_helper(vars, vars->exit->enabled->img, vars->exit->x, vars->exit->y);
	d_anim_helper(vars, vars->p1->idle->img, vars->p1->x, vars->p1->y);
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
	vars->map = malloc(sizeof(map));
	if (vars->map == NULL)
		malloc_er(vars, mat, rc);
	vars->map->mat = mat;
	vars->map->rc = rc;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, rc[1] * 60, rc[0] * 60, "HELLO");
	mlx_loop_hook(vars->mlx, callbacks, vars);
	mlx_hook(vars->win, 2, 0, events, vars);
	mlx_hook(vars->win, 3, 0, on_release, vars);
	mlx_hook(vars->win, 17, 0, quit, vars);
	mlx_loop(vars->mlx);
	return (0);
}
