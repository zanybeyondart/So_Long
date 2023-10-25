/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:44:59 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/25 17:07:35 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	free_game(game *game, t_vars *vars)
{
	if (game)
	{
		free_game(game->next, vars);
		mlx_destroy_image(game->img, vars);
		free(game);
	}
}

void	free_enemies(t_enem_info *enemies, t_vars *vars)
{
	if (enemies)
	{
		if (enemies->right_anim && enemies->left_anim)
		{
			free_animation(enemies->right_anim, vars);
			free_animation(enemies->left_anim, vars);
		}
		free_enemies(enemies->next, vars);
		free(enemies);
	}
}

void	free_power(t_power *power, t_vars *vars)
{
	free_animation(power->anim, vars);
	free_animation(power->anim_l, vars);
	free(power);
}

void	free_kill(t_kill *kill, t_vars *vars)
{
	free_animation(kill->anim, vars);
	free(kill);
}

void	free_vars(t_vars *vars)
{
	if (vars)
	{
		free_player(vars->p1, vars);
		free_portal(vars->exit, vars);
		free_animation(vars->wall, vars);
		free_map(vars->map);
		free_animation(vars->food, vars);
		free_animation(vars->base, vars);
		free_enemies(vars->enemies, vars);
		free_power(vars->power , vars);
		free_kill(vars->kill, vars);
		free(vars);
	}
}
