/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_screen_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:37:01 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/05 05:12:58 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

void	game_state_nav_keys(int keycode, t_vars *vars)
{
	if (keycode == S)
	{
		if (vars->start_screen->option != 3
			&& vars->start_screen->option != 4)
			vars->start_screen->option++;
		else if (vars->start_screen->option != 4)
			vars->start_screen->option = 1;
	}
	if (keycode == W)
	{
		if (vars->start_screen->option != 1
			&& vars->start_screen->option != 4)
			vars->start_screen->option--;
		else if (vars->start_screen->option != 4)
			vars->start_screen->option = 3;
	}
}

void	game_state_en_esc_keys(int keycode, t_vars *vars)
{
	if (keycode == 36)
	{
		if (vars->start_screen->option == 1)
			vars->game_state = 2;
		if (vars->start_screen->option == 2)
			vars->start_screen->option = 4;
		if (vars->start_screen->option == 3)
			quit(vars);
	}
	if (keycode == 53)
	{
		if (vars->start_screen->option == 4)
			vars->start_screen->option = 2;
		else
			quit(vars);
	}
}

void	game_state_1_keys(int keycode, t_vars *vars)
{
	if (keycode == 36 || keycode == 53)
		game_state_en_esc_keys(keycode, vars);
	if (keycode == W || keycode == S)
		game_state_nav_keys(keycode, vars);
}

void	load_start_anims(t_vars *vars)
{
	vars->start_screen->o1 = malloc(sizeof(t_animation));
	if (!vars->start_screen->o1)
		malloc_er(vars, NULL, NULL);
	vars->start_screen->o1->img = NULL;
	vars->start_screen->o1->next = NULL;
	vars->start_screen->o2 = malloc(sizeof(t_animation));
	if (!vars->start_screen->o2)
		malloc_er(vars, NULL, NULL);
	vars->start_screen->o2->img = NULL;
	vars->start_screen->o2->next = NULL;
	vars->start_screen->o3 = malloc(sizeof(t_animation));
	if (!vars->start_screen->o3)
		malloc_er(vars, NULL, NULL);
	vars->start_screen->o3->img = NULL;
	vars->start_screen->o3->next = NULL;
	vars->start_screen->o4 = malloc(sizeof(t_animation));
	if (!vars->start_screen->o4)
		malloc_er(vars, NULL, NULL);
	vars->start_screen->o4->img = NULL;
	vars->start_screen->o4->next = NULL;
	load_o1(vars, vars->start_screen->o1);
	load_o2(vars, vars->start_screen->o2);
	load_o3(vars, vars->start_screen->o3);
	load_o4(vars, vars->start_screen->o4);
}

void	load_screen_1(t_vars *vars)
{
	vars->start_screen = malloc(sizeof(t_menu));
	if (!vars->start_screen)
		malloc_er(vars, NULL, NULL);
	vars->start_screen->o1 = NULL;
	vars->start_screen->o2 = NULL;
	vars->start_screen->o3 = NULL;
	vars->start_screen->o4 = NULL;
	vars->start_screen->option = 1;
	load_start_anims(vars);
}
