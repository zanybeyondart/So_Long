/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:06:19 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/25 17:11:04 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	free_animation(animation *anim, t_vars *vars)
{
	if (anim)
	{
		free_animation(anim->next, vars);
		mlx_destroy_image(vars->mlx, anim->img);
		free(anim);
	}
}

void	free_player(player *p, t_vars *vars)
{
	if (p)
	{
		free_animation(p->idle, vars);
		free_animation(p->idle_l, vars);
		free_animation(p->run, vars);
		free_animation(p->run_l, vars);
		free(p);
	}
}

void	free_portal(portal *p, t_vars *vars)
{
	if (p)
	{
		free_animation(p->disabled, vars);
		free_animation(p->enabled, vars);
		free(p);
	}
}


