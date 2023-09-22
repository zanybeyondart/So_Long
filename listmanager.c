#include "game.h"

char *pather(char *main, int frame, char *ext, char *path)
{
	int	index0;
	int index1;
	int fd;
	path = malloc(30);
	index0 = 0;
	index1 = 0;
	while (main[index0] != '\0')
		path[index1++] = main[index0++];
	index0 = 0;
	path[index1++] = frame + '0';
	while(ext[index0] != '\0')
		path[index1++] = ext[index0++];
	path[index1] = '\0';
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(path);
		return(NULL);
	}
	else
	{
		close(fd);
		return(path);
	}
}

void add_next_frame(t_vars *vars, char *path, animation *sprite)
{
	animation	*temp;
	while(sprite->next)
	sprite = sprite->next;
	temp = malloc(sizeof(animation));
	temp->img = mlx_xpm_file_to_image(vars->mlx, path, &temp->w, &temp->h);
	sprite->next = temp;
}

void assign_anim(t_vars *vars, char *path)
{
	printf("%s\n", path);
	if(!vars->p1->idle)
    vars->p1->idle = malloc(sizeof(animation));
    if(!vars->p1->idle->img)
    vars->p1->idle->img = mlx_xpm_file_to_image(vars->mlx, path, &vars->p1->idle->w, &vars->p1->idle->h);
	else
	add_next_frame(vars, path, vars->p1->idle);
	free(path);
}

