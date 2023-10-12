#include "game.h"

void load_anim_idle(t_vars *vars, animation *sprite)
{
	static int i;
	char *path;

	path = NULL;
	while( i != -1)
	{
	path = pather("./textures/idle/PNG/idle", i, ".xpm", path);
	if (path == NULL)
	i = -1;
	else
	{
	add_frames(vars, path, sprite);
	i++;
	}
	}
}

void load_anim_run(t_vars *vars, animation *sprite)
{
	static int i;
	char *path;

	path = NULL;
	while( i != -1)
	{
	path = pather("./textures/run/PNG/run", i, ".xpm", path);
	if (path == NULL)
	i = -1;
	else
	{
	add_frames(vars, path, sprite);
	i++;
	}
	}
}

int loadplayers(t_vars *vars)
{
	int i = 0;
	int j = 0;
	if(!vars->game)
	{
	vars->game = malloc (sizeof(game));
	vars->game->img = mlx_xpm_file_to_image(vars->mlx, "./textures/Walls/PNG/wall.xpm", &vars->game->w, &vars->game->h);
	}
	if (!vars->p1)
	{
    vars->p1 = malloc(sizeof(player));
	while(i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			if (vars->map->mat[i][j] == P)
			{
			vars->p1->x = j * vars->game->w;
			vars->p1->y = i * vars->game->h;
			}
			j++;
		}
		j = 0;
		i++;
	}
	}
	if (!vars->p1->idle)
	{
	vars->p1->idle = malloc(sizeof(animation));
	load_anim_idle(vars, vars->p1->idle);
	}
	if (!vars->p1->run)
	{
	vars->p1->run = malloc(sizeof(animation));
	load_anim_run(vars, vars->p1->run);
	}
	return(0);
}

