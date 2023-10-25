/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:42:55 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/25 17:34:27 by zvakil           ###   ########.fr       */
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
	if (vars->game_state == 2)
		game_state_2_keys(keycode, vars);
	if (keycode == 53)
		quit(vars);
	return (0);
}

int	callbacks(t_vars *vars)
{
	if (vars->game_state == 1)
	{
		vars->game_state = 2;
	}
	if (vars->game_state == 2)
		game_state_2_render(vars);
	return (0);
}

int	on_release(int keycode, t_vars *vars)
{
	if ((keycode == W || keycode == A || keycode == S || keycode == D)
		&& vars->game_state == 2)
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
	vars->game_state = 1;
	vars->map = NULL;
	vars->map = malloc(sizeof(map));
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
