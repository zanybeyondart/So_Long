/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_lose_screen_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:37:01 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/05 06:32:36 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

void	game_state5_nav_keys(t_vars *vars)
{
	if (vars->end_lose_screen->option == 1)
		vars->end_lose_screen->option = 2;
	else
		vars->end_lose_screen->option = 1;
}

void	game_state5_en_esc_keys(int keycode, t_vars *vars)
{
	if (keycode == 36)
	{
		if (vars->end_lose_screen->option == 1)
			restart_game(vars);
		if (vars->end_lose_screen->option == 2)
			quit(vars);
	}
	if (keycode == 53)
		quit(vars);
}

void	game_state_5_keys(int keycode, t_vars *vars)
{
	if (keycode == 36 || keycode == 53)
		game_state5_en_esc_keys(keycode, vars);
	if (keycode == W || keycode == S)
		game_state5_nav_keys(vars);
}

void	load_end_lose_anims(t_vars *vars)
{
	vars->end_lose_screen->o1 = malloc(sizeof(t_animation));
	if (!vars->end_lose_screen->o1)
		malloc_er(vars, NULL, NULL);
	vars->end_lose_screen->o1->img = NULL;
	vars->end_lose_screen->o1->next = NULL;
	vars->end_lose_screen->o2 = malloc(sizeof(t_animation));
	if (!vars->end_lose_screen->o2)
		malloc_er(vars, NULL, NULL);
	vars->end_lose_screen->o2->img = NULL;
	vars->end_lose_screen->o2->next = NULL;
	vars->end_lose_screen->o3 = malloc(sizeof(t_animation));
	if (!vars->end_lose_screen->o3)
		malloc_er(vars, NULL, NULL);
	vars->end_lose_screen->o3->img = NULL;
	vars->end_lose_screen->o3->next = NULL;
	vars->end_lose_screen->o4 = malloc(sizeof(t_animation));
	if (!vars->end_lose_screen->o4)
		malloc_er(vars, NULL, NULL);
	vars->end_lose_screen->o4->img = NULL;
	vars->end_lose_screen->o4->next = NULL;
	load_end_lose_o1(vars, vars->end_lose_screen->o1);
	load_end_lose_o2(vars, vars->end_lose_screen->o2);
}

void	load_screen_5(t_vars *vars)
{
	vars->end_lose_screen = malloc(sizeof(t_menu));
	if (!vars->end_lose_screen)
		malloc_er(vars, NULL, NULL);
	vars->end_lose_screen->o1 = NULL;
	vars->end_lose_screen->o2 = NULL;
	vars->end_lose_screen->o3 = NULL;
	vars->end_lose_screen->o4 = NULL;
	vars->end_lose_screen->option = 1;
	vars->end_lose_screen->frame = 0;
	load_end_lose_anims(vars);
}
