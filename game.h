#ifndef GAME_H
#define GAME_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <strings.h>
#include "./get_next_line/get_next_line.h"

#define MLX_SYNC_IMAGE_WRITABLE		1
#define MLX_SYNC_WIN_FLUSH_CMD		2
#define MLX_SYNC_WIN_CMD_COMPLETED	3
#define SPEED	15
#define W	13
#define A	0
#define S	1
#define D	2
#define P 32
#define C 19
#define E 21

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

typedef struct map_info
{
	int **mat;
	int *rc;
}map;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	player	*p1;
	map *map;
	game *game;
	animation *food;
} t_vars;

typedef struct map{
	int w;
	int c;
	int p;
	int e;
	int xtra;
} map_errs;


// MAIN.C
void quit(t_vars *vars);
int events(int keycode, t_vars *vars);
int callbacks(t_vars *vars);
int game_start(int **mat, int *rc);



// FREES.C
void free_animation(animation *anim);
void free_player(player *p);
void free_vars(t_vars *vars);
void free_wall(game *game);
void free_map(map *map);

// POSITION_HELPERS.C
void	update_pos(int keycode, player *p1, t_vars *vars);
int pos_check_2(int pc, int pv, int key, t_vars *vars, int *er);



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
void wall (t_vars *vars);


//MAPS.C

int check_map();
int **matrix_create(int *rc, int **mat);
int *fill_row(int *row, int fd, int lim);
int set_r_c(int *rc);
int check_matrix(int **mat, int row, int col);
int path_valid(int **mat);



#endif
