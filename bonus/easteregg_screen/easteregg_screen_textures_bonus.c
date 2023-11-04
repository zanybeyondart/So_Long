/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easteregg_screen_textures_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:35:30 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/04 20:00:10 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

void	load_easteregg_o1(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures/easteregg_screen/o1/", i, ".xpm", path);
		if (path == NULL)
		{
			i = vars->easteregg_screen->frame;
			break ;
		}
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}

void	load_easteregg_o2(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures/easteregg_screen/o1/", i, ".xpm", path);
		if (path == NULL)
			break ;
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}

void	load_cursor(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures/magic/", i, ".xpm", path);
		if (path == NULL)
		{
			vars->cursor_frame = i;
			break ;
		}
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}
