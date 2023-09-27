#include "game.h"

void d_anim_helper(t_vars *vars, animation *temp)
{
	static int y = 0;
	if (y % 15 == 0 && vars->p1->move == 0)
	{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, temp->img, (vars->p1->x), (vars->p1->y));
	mlx_put_image_to_window(vars->mlx, vars->win, vars->game->img, vars->game->x, vars->game->y);

	}
	if (y % 8 == 0 && vars->p1->move == 1)
	{
	mlx_clear_window(vars->mlx, vars->win);
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