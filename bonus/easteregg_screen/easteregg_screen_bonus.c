/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easteregg_screen_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:37:01 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/05 09:20:58 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

void	load_easteregg_anims(t_vars *vars)
{
	vars->easteregg_screen->o1 = malloc(sizeof(t_animation));
	if (!vars->easteregg_screen->o1)
		malloc_er(vars, NULL, NULL);
	vars->easteregg_screen->o1->img = NULL;
	vars->easteregg_screen->o1->next = NULL;
	vars->easteregg_screen->o2 = malloc(sizeof(t_animation));
	if (!vars->easteregg_screen->o2)
		malloc_er(vars, NULL, NULL);
	vars->easteregg_screen->o2->img = NULL;
	vars->easteregg_screen->o2->next = NULL;
	vars->cursor = malloc(sizeof(t_animation));
	if (!vars->cursor)
		malloc_er(vars, NULL, NULL);
	vars->cursor->img = NULL;
	vars->cursor->next = NULL;
	vars->easteregg_text = malloc(sizeof(t_animation));
	if (!vars->easteregg_text)
		malloc_er(vars, NULL, NULL);
	vars->easteregg_text->img = NULL;
	vars->easteregg_text->next = NULL;
	load_easteregg_o1(vars, vars->easteregg_screen->o1);
	load_easteregg_o2(vars, vars->easteregg_screen->o2);
	load_cursor(vars, vars->cursor);
	load_easteregg_text(vars, vars->easteregg_text);
}

void	load_screen_6(t_vars *vars)
{
	vars->easteregg_screen = malloc(sizeof(t_menu));
	if (!vars->easteregg_screen)
		malloc_er(vars, NULL, NULL);
	vars->easteregg_screen->o1 = NULL;
	vars->easteregg_screen->o2 = NULL;
	vars->easteregg_screen->o3 = NULL;
	vars->easteregg_screen->o4 = NULL;
	vars->easteregg_screen->option = 1;
	vars->easteregg_screen->frame = 0;
	load_easteregg_anims(vars);
}

int	mouse_move(int x, int y, t_vars *vars)
{
	mlx_mouse_get_pos(vars->win, &x, &y);
	vars->cursor_x = x;
	vars->cursor_y = y;
	return (0);
}

int	easter_egg(int button, int x, int y, t_vars *vars)
{
	static int	i;

	x = vars->cursor_x;
	y = vars->cursor_y;
	if (button == 1 && vars->p1->move_count == 42
		&& (x > (vars->map->rc[1] / 2) * 60 - 3 *(vars->number->w / 2)
			&& x < (vars->map->rc[1] / 2) * 60 + 1.5 * vars->number->w)
		&& (y > vars->map->rc[0] * 60 + 5
			&& y < vars->map->rc[0] * 60 + 5 + vars->number->h) && i != -99)
	{
		vars->game_state = 6;
		i = -99;
		easteregg_found(vars, vars->easteregg_text);
		easteregg_found(vars, vars->easteregg_text);
		easteregg_found(vars, vars->easteregg_text);
		easteregg_found(vars, vars->easteregg_text);
		easteregg_found(vars, vars->easteregg_text);
		mlx_mouse_hide();
	}
	return (0);
}
