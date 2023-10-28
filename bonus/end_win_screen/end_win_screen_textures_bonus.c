/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_win_screen_textures_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:35:30 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/28 14:10:46 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

void	load_end_win_o1(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures/end_win_screen/o1/", i, ".xpm", path);
		if (path == NULL)
		{
			vars->start_screen->frame = i;
			break ;
		}
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}

void	load_end_win_o2(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures/end_win_screen/o2/", i, ".xpm", path);
		if (path == NULL)
		{
			break ;
		}
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}

void	load_end_win_o3(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures/end_win_screen/o3/", i, ".xpm", path);
		if (path == NULL)
		{
			break ;
		}
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}

void	load_end_win_o4(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures/end_win_screen/o4/", i, ".xpm", path);
		if (path == NULL)
		{
			break ;
		}
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}
