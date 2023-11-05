/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:06:19 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/05 09:03:09 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

void	free_menu(t_menu *menu, t_vars *vars)
{
	if (menu->o1)
		free_animation(menu->o1, vars);
	if (menu->o2)
		free_animation(menu->o2, vars);
	if (menu->o3)
		free_animation(menu->o3, vars);
	if (menu->o4)
		free_animation(menu->o4, vars);
	free(menu);
}

void	free_animation(t_animation *anim, t_vars *vars)
{
	if (anim)
	{
		free_animation(anim->next, vars);
		if (anim->img)
			mlx_destroy_image(vars->mlx, anim->img);
		free(anim);
	}
}

void	free_player(t_player *p, t_vars *vars)
{
	if (p)
	{
		free_animation(p->idle, vars);
		free_animation(p->idle_l, vars);
		free_animation(p->run, vars);
		free_animation(p->run_l, vars);
		free_animation(p->death_l, vars);
		free_animation(p->death_r, vars);
		free_animation(p->win_l, vars);
		free_animation(p->win_r, vars);
		free(p);
	}
}

void	free_portal(t_portal *p, t_vars *vars)
{
	if (p)
	{
		free_animation(p->disabled, vars);
		free_animation(p->enabled, vars);
		free(p);
	}
}
