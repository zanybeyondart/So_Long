/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easteregg_text_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:33:39 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/04 17:37:47 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

void	load_easteregg_text(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = pather("./textures/easteregg_text/", i, ".xpm", path);
		if (path == NULL)
			break ;
		else
		{
			add_frames(vars, path, sprite);
			i++;
		}
	}
}

t_animation	*egg_text_image_helper(int frame, t_animation *temp)
{
	int	i;

	i = 0;
	while (i < frame)
	{
		temp = temp->next;
		i++;
	}
	return (temp);
}

t_animation	*egg_text_image(t_animation *sprite, int frame)
{
	static int	i;
	t_animation	*temp;

	temp = sprite;
	if (i >= frame - 1)
		i = 0;
	else
		i++;
	return (egg_text_image_helper(i, temp));
}

int	easteregg_found(t_vars *vars, t_animation *temp)
{
	if (temp)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->base->img, 0, 0);
		wall_set(vars);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->exit->active->img, vars->exit->x, vars->exit->y);
		food_rend(vars);
		moves_rend(vars);
		enemies_list_send(vars);
		if (vars->kill->spawn == 1)
			kill_rend(vars);
		power_rend(vars);
		player_rend(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, temp->img,
			((vars->map->rc[1] / 2) * 60) - (temp->w / 2),
			((vars->map->rc[0] / 2) * 60));
		mlx_do_sync(vars->mlx);
		usleep(100000);
		return (easteregg_found(vars, temp->next));
	}
	return (1);
}
