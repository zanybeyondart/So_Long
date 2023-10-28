/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:11:37 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/28 14:11:16 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

void	load_anim_kill(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures/kill/kill", i, ".xpm", path);
		if (path == NULL)
		{
			vars->kill->frames = i;
			break ;
		}
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}

void	load_kill(t_vars *vars)

{
	vars->kill = malloc(sizeof(t_kill));
	if (vars->kill == NULL)
		malloc_er(vars, NULL, NULL);
	vars->kill->anim = NULL;
	vars->kill->spawn = 0;
	vars->kill->anim = malloc(sizeof(t_animation));
	if (vars->kill->anim == NULL)
		malloc_er(vars, NULL, NULL);
	vars->kill->anim->img = NULL;
	vars->kill->anim->next = NULL;
	load_anim_kill(vars, vars->kill->anim);
}
