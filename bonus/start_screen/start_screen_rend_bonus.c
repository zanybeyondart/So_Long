/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_screen_rend_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:18:05 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/04 19:21:08 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

t_animation	*menu_image_helper(int frame, t_animation *temp)
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

t_animation	*menu_image(t_animation *sprite, int frame)
{
	static int	i;
	t_animation	*temp;

	temp = sprite;
	if (i >= frame - 1)
		i = 0;
	else
		i++;
	return (menu_image_helper(i, temp));
}

void	game_state_1_render(t_vars *vars)
{
	t_animation	*temp;

	temp = NULL;
	if (vars->start_screen->option == 1)
		temp = menu_image(vars->start_screen->o1, 10);
	else if (vars->start_screen->option == 2)
		temp = menu_image(vars->start_screen->o2, 10);
	else if (vars->start_screen->option == 3)
		temp = menu_image(vars->start_screen->o3, 10);
	else if (vars->start_screen->option == 4)
		temp = menu_image(vars->start_screen->o4, 10);
	usleep(100000);
	mlx_put_image_to_window(vars->mlx, vars->win, temp->img, 0, 0);
}
