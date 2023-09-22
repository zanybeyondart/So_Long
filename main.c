#include "game.h"

void quit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_vars(vars);
	exit(1);
}

void putscreen (t_vars *vars, animation *temp)
{
	static int y = 0;
	if (y % 30 == 0)
	mlx_put_image_to_window(vars->mlx, vars->win, temp->img, 50, 50);
	mlx_do_sync(vars->mlx);
	y++;
	if (y > 1000000)
	y = 0;

}

void display_anim(t_vars *vars, animation *sprite)
{
	while (sprite)
	{
		putscreen(vars, sprite);
		sprite = sprite->next;
	}
}

int loadplayers(t_vars *vars)
{		
	static int i;
	char *path;
	path = NULL;

	if (!vars->p1)
    vars->p1 = malloc(sizeof(player));

	while( i != -1)
	{
	path = pather("./textures/idle/xpm/idle", i, ".xpm", path);
	if (path == NULL)
	i = -1;
	else
	{
	assign_anim(vars, path);
	i++;
	}
	}
	return(0);
}

int player_idle_animation(int keycode, t_vars *vars)
{
	if (keycode == 53)
	quit(vars);
	return(0);
}

int callbacks(t_vars *vars)
{
	loadplayers(vars);
	display_anim(vars, vars->p1->idle);

	return(0);
}

int main(void)
{
    t_vars  *vars;
	vars = malloc(sizeof(t_vars));
    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, 640, 480, "HELLO");
	mlx_loop_hook(vars->mlx, callbacks, vars);
	mlx_hook(vars->win, 2, 0, player_idle_animation, vars);
    mlx_loop(vars->mlx);
	return (0);
}

