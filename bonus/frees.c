/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:44:59 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/20 22:19:27 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	free_animation(animation *anim, t_vars *vars)
{
	if (anim)
	{
		free_animation(anim->next, vars);
		mlx_destroy_image(vars->mlx, anim->img);
		free(anim);
	}
}

void	free_player(player *p, t_vars *vars)
{
	if (p)
	{
		free_animation(p->idle, vars);
		free_animation(p->run, vars);
		free(p);
	}
}

void	free_game(game *game, t_vars *vars)
{
	if (game)
	{
		free_game(game->next, vars);
		mlx_destroy_image(game->img, vars);
		free(game);
	}
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
		free(vars);
	}
}
