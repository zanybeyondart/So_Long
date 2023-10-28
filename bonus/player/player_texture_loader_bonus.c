/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_texture_loader_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:50:12 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/28 14:11:14 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

void	load_anim_idle(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures/Player/Idle_r/idle", i, ".xpm", path);
		if (path == NULL)
		{
			vars->p1->idle_frames = i;
			break ;
		}
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}

void	load_anim_idle_2(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures/Player/Idle_l/idle", i, ".xpm", path);
		if (path == NULL)
		{
			vars->p1->idle_frames = i;
			break ;
		}
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}

void	load_anim_run(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures/Player/run_r/run", i, ".xpm", path);
		if (path == NULL)
		{
			vars->p1->run_frames = i;
			break ;
		}
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}

void	load_anim_run_2(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures/Player/run_l/run", i, ".xpm", path);
		if (path == NULL)
		{
			vars->p1->run_frames = i;
			break ;
		}
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}
