#ifndef GAME_H
#define GAME_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <strings.h>

typedef struct frames{
	void *img;
	int w;
	int h;
	struct frames *next;
} animation;

typedef struct list
{
	animation *idle;
}player;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	player	*p1;
} t_vars;


char *pather(char *main, int frame, char *ext, char *path);
void add_next_frame(t_vars *vars, char *path, animation *sprite);
void assign_anim(t_vars *vars, char *path);
void free_animation(animation *anim);
void free_player(player *p);
void free_vars(t_vars *vars);
void quit(t_vars *vars);
int loadplayers(t_vars *vars);
int check_new(t_vars *vars, char *path);



#endif