#ifndef GAME_H
#define GAME_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <strings.h>

#define MLX_SYNC_IMAGE_WRITABLE		1
#define MLX_SYNC_WIN_FLUSH_CMD		2
#define MLX_SYNC_WIN_CMD_COMPLETED	3
#define SPEED	10
#define W	13
#define A	0
#define S	1
#define D	2

typedef struct frames{
	void *img;
	int w;
	int h;
	struct frames *next;
} animation;

typedef struct list
{
	animation *idle;
	animation *run;
	int x;
	int y;
	int move;
}player;

typedef struct game_info
{
	void *img;
	int w;
	int h;
	int x;
	int y;
}game;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	player	*p1;
	game *game;
} t_vars;


// MAIN.C
void quit(t_vars *vars);
int events(int keycode, t_vars *vars);
int callbacks(t_vars *vars);
int wall (t_vars *vars);


// FREES.C
void free_animation(animation *anim);
void free_player(player *p);
void free_vars(t_vars *vars);
void free_wall(game *game);

// POSITION_HELPERS.C
void	update_pos(int keycode, player *p1, t_vars *vars);


// LOADERS.C
int loadplayers(t_vars *vars);
void load_anim_idle(t_vars *vars, animation *sprite);
void load_anim_run(t_vars *vars, animation *sprite);




// LISTMANAGER.C
void add_frames(t_vars *vars, char *path, animation *sprite);
void add_frame_helper(t_vars *vars, char *path, animation *sprite);
char *pather(char *main, int frame, char *ext, char *path);




// DISLPAY.C
void d_anim(t_vars *vars, animation *sprite);
void d_anim_helper(t_vars *vars, animation *temp);






#endif
