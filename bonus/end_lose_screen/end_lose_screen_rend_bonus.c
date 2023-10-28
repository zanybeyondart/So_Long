/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_lose_screen_rend_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:18:05 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/28 14:10:41 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

t_animation	*el_menu_image_helper(int frame, t_animation *temp)
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

t_animation	*el_menu_image(t_animation *sprite, int frame)
{
	static int	i;
	t_animation	*temp;

	temp = sprite;
	if (i >= frame - 1)
		i = 0;
	else
		i++;
	return (el_menu_image_helper(i, temp));
}

void	game_state_5_render(t_vars *vars)
{
	t_animation	*temp;

	temp = NULL;
	if (vars->end_lose_screen->option == 1)
		temp = el_menu_image(vars->end_lose_screen->o1,
				vars->end_lose_screen->frame);
	else
		temp = el_menu_image(vars->end_lose_screen->o2,
				vars->end_lose_screen->frame);
	mlx_put_image_to_window(vars->mlx, vars->win, temp->img, 0, 0);
}
