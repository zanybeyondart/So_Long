/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_rend_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:27:26 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/03 11:19:32 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

t_animation	*en_image_helper(int frame, t_animation *temp)
{
	int	i;

	i = 0;
	while (i++ < frame)
	{
		temp = temp->next;
	}
	return (temp);
}

t_animation	*en_image(t_animation *sprite, int frame)
{
	static int	i;
	t_animation	*temp;

	temp = sprite;
	if (i >= frame - 1)
		i = 0;
	else
		i++;
	return (en_image_helper(i, temp));
}

void	enemies_rend(t_vars *vars, t_enem_info *enemy)
{
	t_animation	*temp;

	if (enemy->dir == 1)
		temp = en_image(vars->enemies->right_anim, vars->enemies->frames);
	else
		temp = en_image(vars->enemies->left_anim, vars->enemies->frames);
	mlx_put_image_to_window(vars->mlx, vars->win, temp->img,
		enemy->x, enemy->y);
}

void	enemies_list_send(t_vars *vars)
{
	t_enem_info	*temp;

	temp = NULL;
	temp = vars->enemies;
	while (temp)
	{
		if (temp->alive == 0)
			enemies_rend(vars, temp);
		temp = temp->next;
	}
}
