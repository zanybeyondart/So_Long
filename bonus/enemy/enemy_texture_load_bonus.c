/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_texture_load_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:07:58 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/25 16:09:27 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	load_anim_enemy_right(t_vars *vars, animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures/Enemy/right/enemy", i, ".xpm", path);
		if (path == NULL)
		{
			vars->enemies->frames = i;
			break ;
		}
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}

void	load_anim_enemy_left(t_vars *vars, animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures/Enemy/left/enemy", i, ".xpm", path);
		if (path == NULL)
			break ;
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}
