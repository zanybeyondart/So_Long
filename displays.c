#include "game.h"

void food (t_vars *vars)
{
	int i = 0;
	int j = 0;
	animation *temp;
	temp = vars->food;
	while(i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			if (vars->map->mat[i][j] == C)
			{
			mlx_put_image_to_window(vars->mlx, vars->win, temp->img, j * vars->game->w + 10, i * vars->game->h + 10);
			if (temp->next)
			temp = temp->next;
			else 
			temp = vars->food;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void wall (t_vars *vars)
{
	int i = 0;
	int j = 0;
	while(i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			if (vars->map->mat[i][j] == 1)
			{
			vars->game->x = j * vars->game->w;
			vars->game->y = i * vars->game->h;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->game->img, vars->game->x, vars->game->y);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void d_anim_helper(t_vars *vars, animation *temp)
{
	static int y = 0;
	if (y % 8 == 0 && vars->p1->move == 0)
	{
	mlx_clear_window(vars->mlx, vars->win);
	wall(vars);
	food(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, temp->img, (vars->p1->x), (vars->p1->y));
	mlx_put_image_to_window(vars->mlx, vars->win, vars->game->img, vars->game->x, vars->game->y);

	}
	if (y % 8 == 0 && vars->p1->move == 1)
	{
	mlx_clear_window(vars->mlx, vars->win);
	wall(vars);
	food(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, temp->img, (vars->p1->x), (vars->p1->y));
	mlx_put_image_to_window(vars->mlx, vars->win, vars->game->img, vars->game->x, vars->game->y);
	}
	mlx_do_sync(vars->mlx);
	y++;
	if (y > 1000000)
	y = 0;

}

void d_anim(t_vars *vars, animation *sprite)
{
	while (sprite)
	{
		d_anim_helper(vars, sprite);
		sprite = sprite->next;
	}
}