/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:51:09 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/28 14:10:51 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

void	load_enemies_head(t_vars *vars, int i, int j)
{
	vars->enemies->x = j * vars->wall->w + 10;
	vars->enemies->y = i * vars->wall->h + 10;
	vars->enemies->dir = 1;
	vars->enemies->active = 0;
	vars->enemies->r_wall = enemy_wall_col(vars, i, j, 1);
	vars->enemies->l_wall = enemy_wall_col(vars, i, j, -1);
	vars->enemies->next = NULL;
}

void	load_enemies(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	vars->enemies = malloc(sizeof(t_enem_info));
	if (vars->enemies == NULL)
		malloc_er(vars, NULL, NULL);
	vars->enemies->x = 0;
	vars->enemies->right_anim = NULL;
	vars->enemies->left_anim = NULL;
	vars->enemies->alive = 1;
	while (i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			if (vars->map->mat[i][j] == V && vars->enemies->x == 0)
				load_enemies_head(vars, i, j);
			else if (vars->map->mat[i][j] == V)
				enemy_list(vars, vars->enemies, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

void	load_enemy_anims(t_vars *vars)
{
	vars->enemies->right_anim = malloc(sizeof(t_animation));
	if (vars->enemies->right_anim == NULL)
		malloc_er(vars, NULL, NULL);
	vars->enemies->right_anim->img = NULL;
	vars->enemies->right_anim->next = NULL;
	load_anim_enemy_right(vars, vars->enemies->right_anim);
	vars->enemies->left_anim = malloc(sizeof(t_animation));
	if (vars->enemies->left_anim == NULL)
		malloc_er(vars, NULL, NULL);
	vars->enemies->left_anim->img = NULL;
	vars->enemies->left_anim->next = NULL;
	load_anim_enemy_left(vars, vars->enemies->left_anim);
}

void	enemy_list(t_vars *vars, t_enem_info *enemies, int i, int j)
{
	t_enem_info	*temp;

	temp = malloc(sizeof(t_enem_info));
	if (temp == NULL)
		malloc_er(vars, NULL, NULL);
	temp->x = j * vars->wall->w + 10;
	temp->y = i * vars->wall->h + 10;
	temp->dir = 1;
	temp->r_wall = enemy_wall_col(vars, i, j, 1);
	temp->l_wall = enemy_wall_col(vars, i, j, -1);
	temp->left_anim = NULL;
	temp->right_anim = NULL;
	temp->alive = 0;
	temp->next = NULL;
	while (enemies->next)
		enemies = enemies->next;
	enemies->next = temp;
}
