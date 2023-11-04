/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easteregg_screen_rend_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:18:05 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/04 20:01:02 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

t_animation	*magic_image_helper(int frame, t_animation *temp)
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

t_animation	*magic_image(t_animation *sprite, int frame)
{
	static int	i;
	t_animation	*temp;

	temp = sprite;
	if (i >= frame - 1)
		i = 0;
	else
		i++;
	return (magic_image_helper(i, temp));
}

t_animation	*easter_menu_image_helper(int frame, t_animation *temp)
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

t_animation	*easter_menu_image(t_animation *sprite, int frame)
{
	static int	i;
	t_animation	*temp;

	temp = sprite;
	if (i >= frame - 1)
		i = 0;
	else
		i++;
	return (easter_menu_image_helper(i, temp));
}

void	game_state_6_render(t_vars *vars)
{
	t_animation	*temp;
	t_animation	*temp2;

	temp = NULL;
	temp2 = NULL;
	temp = easter_menu_image(vars->easteregg_screen->o1,
			10);
	temp2 = magic_image(vars->cursor, vars->cursor_frame);
	usleep(100000);
	mlx_put_image_to_window(vars->mlx, vars->win, temp->img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, temp2->img,
		vars->cursor_x - (vars->cursor->w / 2),
		vars->cursor_y - (vars->cursor->h / 2));
}
