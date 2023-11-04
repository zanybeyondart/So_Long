/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:38:29 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/04 17:15:12 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

void	load_anim_power_2(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures_bonus/power/left/", i, ".xpm", path);
		if (path == NULL)
		{
			vars->power->frames = i;
			break ;
		}
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}

void	load_anim_power(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures_bonus/power/right/", i, ".xpm", path);
		if (path == NULL)
		{
			vars->power->frames = i;
			break ;
		}
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}

void	load_power(t_vars *vars)
{
	vars->power = malloc(sizeof(t_power));
	if (vars->power == NULL)
		malloc_er(vars, NULL, NULL);
	vars->power->anim = NULL;
	vars->power->anim_l = NULL;
	vars->power->spawn = 0;
	vars->power->anim = malloc(sizeof(t_animation));
	if (vars->power->anim == NULL)
		malloc_er(vars, NULL, NULL);
	vars->power->anim->img = NULL;
	vars->power->anim->next = NULL;
	vars->power->anim_l = malloc(sizeof(t_animation));
	if (vars->power->anim_l == NULL)
		malloc_er(vars, NULL, NULL);
	vars->power->anim_l->img = NULL;
	vars->power->anim_l->next = NULL;
	load_anim_power(vars, vars->power->anim);
	load_anim_power_2(vars, vars->power->anim_l);
}
