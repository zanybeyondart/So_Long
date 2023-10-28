/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_screen_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:25:30 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/28 14:10:59 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

void	game_state_2_render(t_vars *vars)
{
	usleep(100000);
	enemy_updates(vars->enemies, vars);
	power_updates(vars);
	power_check(vars);
	game_checks(vars);
	mlx_clear_window(vars->mlx, vars->win);
	main_display(vars);
	mlx_do_sync(vars->mlx);
}

void	game_state_2_keys(int keycode, t_vars *vars)
{
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		update_pos(keycode, vars->p1, vars);
	if (keycode == 49 && vars->power->spawn == 0)
	{
		if (vars->p1->dir == 1)
			vars->power->spawn = 1;
		else
			vars->power->spawn = -1;
		vars->power->x = vars->p1->x;
		vars->power->y = vars->p1->y;
	}
}
