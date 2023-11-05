/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:42:55 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/05 05:13:12 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

int	events(int keycode, t_vars *vars)
{
	if (keycode == 53 && vars->game_state == 2)
		vars->game_state = 3;
	else if (vars->game_state == 2)
		game_state_2_keys(keycode, vars);
	else if (vars->game_state == 1)
		game_state_1_keys(keycode, vars);
	else if (vars->game_state == 3)
		game_state_3_keys(keycode, vars);
	else if (vars->game_state == 4)
		game_state_4_keys(keycode, vars);
	else if (vars->game_state == 5)
		game_state_5_keys(keycode, vars);
	else if (vars->game_state == 6)
		if (keycode == 53)
			quit(vars);
	return (0);
}

int	callbacks(t_vars *vars)
{
	if (vars->game_state == 1)
		game_state_1_render(vars);
	if (vars->game_state == 2)
		game_state_2_render(vars);
	if (vars->game_state == 3)
		game_state_3_render(vars);
	if (vars->game_state == 4)
		game_state_4_render(vars);
	if (vars->game_state == 5)
		game_state_5_render(vars);
	if (vars->game_state == 6)
		game_state_6_render(vars);
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
		malloc_er(vars, NULL, NULL);
	vars->game_state = 1;
	vars->map = NULL;
	vars->map = malloc(sizeof(t_map));
	if (vars->map == NULL)
		malloc_er(vars, mat, rc);
	vars->map->mat = mat;
	vars->map->rc = rc;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, rc[1] * 60,
			(rc[0] + 1) * 60, "DINO WARS");
	loadplayers(vars);
	mlx_loop_hook(vars->mlx, callbacks, vars);
	mlx_hook(vars->win, 2, 0, events, vars);
	mlx_hook(vars->win, 3, 0, on_release, vars);
	mlx_hook(vars->win, 6, 0, mouse_move, vars);
	mlx_hook(vars->win, 4, 0, easter_egg, vars);
	mlx_hook(vars->win, 17, 0, quit, vars);
	mlx_loop(vars->mlx);
	return (0);
}
