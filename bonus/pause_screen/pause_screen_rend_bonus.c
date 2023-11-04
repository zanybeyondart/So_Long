/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause_screen_rend_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:18:05 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/04 19:36:52 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

t_animation	*pmenu_image_helper(int frame, t_animation *temp)
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

t_animation	*pmenu_image(t_animation *sprite, int frame)
{
	static int	i;
	t_animation	*temp;

	temp = sprite;
	if (i >= frame - 1)
		i = 0;
	else
		i++;
	return (pmenu_image_helper(i, temp));
}

void	game_state_3_render(t_vars *vars)
{
	t_animation	*temp;

	temp = NULL;
	if (vars->pause_screen->option == 1)
		temp = pmenu_image(vars->pause_screen->o1, vars->pause_screen->frame);
	else if (vars->pause_screen->option == 2)
		temp = pmenu_image(vars->pause_screen->o2, vars->pause_screen->frame);
	else if (vars->pause_screen->option == 3)
		temp = pmenu_image(vars->pause_screen->o3, vars->pause_screen->frame);
	else if (vars->pause_screen->option == 4)
		temp = pmenu_image(vars->pause_screen->o4, 10);
	usleep(100000);
	mlx_put_image_to_window(vars->mlx, vars->win, temp->img, 0, 0);
}
