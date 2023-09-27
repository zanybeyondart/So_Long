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
	if (!vars->p1)
    vars->p1 = malloc(sizeof(player));
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