/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause_screen_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:37:01 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/05 06:02:45 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

void	game_state3_nav_keys(int keycode, t_vars *vars)
{
	if (keycode == S)
	{
		if (vars->pause_screen->option != 3
			&& vars->pause_screen->option != 4)
			vars->pause_screen->option++;
		else if (vars->pause_screen->option != 4)
			vars->pause_screen->option = 1;
	}
	if (keycode == W)
	{
		if (vars->pause_screen->option != 1
			&& vars->pause_screen->option != 4)
			vars->pause_screen->option--;
		else if (vars->pause_screen->option != 4)
			vars->pause_screen->option = 3;
	}
}

void	game_state3_en_esc_keys(int keycode, t_vars *vars)
{
	if (keycode == 36)
	{
		if (vars->pause_screen->option == 1)
			vars->game_state = 2;
		if (vars->pause_screen->option == 2)
			vars->pause_screen->option = 4;
		if (vars->pause_screen->option == 3)
			quit(vars);
	}
	if (keycode == 53)
	{
		if (vars->pause_screen->option == 4)
			vars->pause_screen->option = 2;
		else
			vars->game_state = 2;
	}
}

void	game_state_3_keys(int keycode, t_vars *vars)
{
	if (keycode == 36 || keycode == 53)
		game_state3_en_esc_keys(keycode, vars);
	if (keycode == W || keycode == S)
		game_state3_nav_keys(keycode, vars);
}

void	load_pause_anims(t_vars *vars)
{
	vars->pause_screen->o1 = malloc(sizeof(t_animation));
	if (!vars->pause_screen->o1)
		malloc_er(vars, NULL, NULL);
	vars->pause_screen->o1->img = NULL;
	vars->pause_screen->o1->next = NULL;
	vars->pause_screen->o2 = malloc(sizeof(t_animation));
	if (!vars->pause_screen->o2)
		malloc_er(vars, NULL, NULL);
	vars->pause_screen->o2->img = NULL;
	vars->pause_screen->o2->next = NULL;
	vars->pause_screen->o3 = malloc(sizeof(t_animation));
	if (!vars->pause_screen->o3)
		malloc_er(vars, NULL, NULL);
	vars->pause_screen->o3->img = NULL;
	vars->pause_screen->o3->next = NULL;
	vars->pause_screen->o4 = malloc(sizeof(t_animation));
	if (!vars->pause_screen->o4)
		malloc_er(vars, NULL, NULL);
	vars->pause_screen->o4->img = NULL;
	vars->pause_screen->o4->next = NULL;
	load_pause_o1(vars, vars->pause_screen->o1);
	load_pause_o2(vars, vars->pause_screen->o2);
	load_pause_o3(vars, vars->pause_screen->o3);
	load_pause_o4(vars, vars->pause_screen->o4);
}

void	load_screen_3(t_vars *vars)
{
	vars->pause_screen = malloc(sizeof(t_menu));
	if (!vars->pause_screen)
		malloc_er(vars, NULL, NULL);
	vars->pause_screen->o1 = NULL;
	vars->pause_screen->o2 = NULL;
	vars->pause_screen->o3 = NULL;
	vars->pause_screen->o4 = NULL;
	vars->pause_screen->option = 1;
	vars->pause_screen->frame = 0;
	load_pause_anims(vars);
}
