/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_screen_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:25:30 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/25 17:36:33 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	game_state_2_render(t_vars *vars)
{
	usleep(100000);
	enemy_updates(vars->enemies, vars);
	power_updates(vars);
	power_check(vars);
	game_checks(vars);
	vars->p1->active = player_img(vars);
	mlx_clear_window(vars->mlx, vars->win);
	main_display(vars);
	d_anim_helper(vars, vars->p1->active->img, vars->p1->x, vars->p1->y);
	mlx_do_sync(vars->mlx);
	if (vars->end == 1)
		quit(vars);
}

void	game_state_2_keys(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
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