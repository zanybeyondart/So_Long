/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:44:59 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/05 09:10:08 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

void	free_enemies(t_enem_info *enemies, t_vars *vars)
{
	if (enemies)
	{
		if (enemies->right_anim && enemies->left_anim)
		{
			free_animation(enemies->right_anim, vars);
			free_animation(enemies->left_anim, vars);
		}
		free_enemies(enemies->next, vars);
		free(enemies);
	}
}

void	free_power(t_power *power, t_vars *vars)
{
	free_animation(power->anim, vars);
	free_animation(power->anim_l, vars);
	free(power);
}

void	free_kill(t_kill *kill, t_vars *vars)
{
	free_animation(kill->anim, vars);
	free(kill);
}

void	free_vars(t_vars *vars)
{
	if (vars)
	{
		free_player(vars->p1, vars);
		free_portal(vars->exit, vars);
		free_animation(vars->wall, vars);
		free_map(vars->map);
		free_animation(vars->food, vars);
		free_animation(vars->base, vars);
		free_enemies(vars->enemies, vars);
		free_power(vars->power, vars);
		free_kill(vars->kill, vars);
		free_animation(vars->number, vars);
		free_menu(vars->start_screen, vars);
		free_menu(vars->pause_screen, vars);
		free_menu(vars->end_lose_screen, vars);
		free_menu(vars->end_win_screen, vars);
		free_menu(vars->easteregg_screen, vars);
		free_animation(vars->cursor, vars);
		free_animation(vars->easteregg_text, vars);
		free(vars);
	}
}
