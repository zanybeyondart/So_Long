#include "game.h"

int check_exit(t_vars *vars)
{
	int i = 0;
	int j = 0;

	while (i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			if (vars->map->mat[i][j] == C)
			{
				if ((vars->p1->y > i * vars->game->h && vars->p1->y < i * vars->game->h + vars->food->h)
				|| (vars->p1->y > i * vars->game->h && vars->p1->y <  i * vars->game->h + vars->food->h))
				if ((vars->p1->x  > j * vars->game->w && vars->p1->x < j * vars->game->w + vars->food->w)
				|| (vars->p1->x + vars->p1->idle->w > j * vars->game->w
				&& vars->p1->x + vars->p1->idle->w < j * vars->game->w + vars->food->w)
				)
				vars->map->mat[i][j] = 0;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void quit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_vars(vars);
	exit(1);
}

int events(int keycode, t_vars *vars)
{
	if (keycode == 53)
	quit(vars);
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2 )
	update_pos(keycode, vars->p1, vars);
	printf("%d\n", keycode);
	return(0);
}


int callbacks(t_vars *vars)
{
	loadplayers(vars);
	check_exit(vars);
	if(vars->p1->move == 0)
	d_anim(vars, vars->p1->idle);
	if(vars->p1->move == 1)
	d_anim(vars, vars->p1->run);
	return(0);
}

int on_release(int keycode, t_vars *vars)
{
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2 )
	vars->p1->move = 0;
	return 0;
}

int game_start(int **mat, int *rc)
{
    t_vars  *vars;
	vars = malloc(sizeof(t_vars));
	vars->map = malloc(sizeof(map));
	vars->map->mat = mat;
	vars->map->rc = rc;
    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, rc[1] * 60, rc[0] * 60, "HELLO");
	mlx_loop_hook(vars->mlx, callbacks, vars);
	mlx_hook(vars->win, 2, 0, events, vars);
	mlx_hook(vars->win, 3, 0, on_release, vars);
    mlx_loop(vars->mlx);
	return (0);
}
