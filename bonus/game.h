/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:29:07 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/21 21:08:16 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <strings.h>
# include "../get_next_line/get_next_line.h"

# define SPEED	15
# define W	13
# define A	0
# define S	1
# define D	2
# define P 32
# define C 19
# define E 21

typedef struct frames{
	void			*img;
	int				w;
	int				h;
	struct frames	*next;
} animation;

typedef struct list
{
	animation *idle;
	animation *run;
	animation *active;
	int x;
	int y;
	int move;
	int move_count;
}player;

typedef struct portal
{
	animation *disabled;
	animation *enabled;
	animation *active;
	int x;
	int y;
	int exit;
}portal;

typedef struct game_objects
{
	void *img;
	int w;
	int h;
	int x;
	int y;
	struct game_objects *next;
}game;

typedef struct map_info
{
	int **mat;
	int *rc;
}map;

typedef struct boundingbox_info
{
	int pv;
	int pc;
	int m_min;
	int m_max;
	int m_bd;
	int bd;
	int min;
	int max;
	int er;
} box;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	player	*p1;
	map *map;
	animation *wall;
	animation *food;
	animation	*base;
	portal *exit;
	int end;
} t_vars;

typedef struct map{
	int w;
	int c;
	int p;
	int e;
	int xtra;
} map_errs;


// MAIN.C
int quit(t_vars *vars);
int events(int keycode, t_vars *vars);
int callbacks(t_vars *vars);
int game_start(int **mat, int *rc);



// FREES.C
void	free_animation(animation *anim, t_vars *vars);
void free_player(player *p, t_vars *vars);
void free_vars(t_vars *vars);
void free_game(game *game, t_vars *vars);

// POSITION_HELPERS.C
void	update_pos(int keycode, player *p1, t_vars *vars);
int pos_check_1(int pc, int pv, int key, t_vars *vars);



// LOADERS.C
int loadplayers(t_vars *vars);
void	load_exit_en_dis(t_vars *vars);
void	load_exit(t_vars *vars);
void	load_wall(t_vars *vars);
void	load_base(t_vars *vars);

// LISTMANAGER.C
void add_frames(t_vars *vars, char *path, animation *sprite);
void add_frame_helper(t_vars *vars, char *path, animation *sprite);
char *pather(char *main, int frame, char *ext, char *path);




// DISLPAY.C
void main_display(t_vars *vars);
animation	*image_helper(int frame, animation *temp);
animation	*image(animation *sprite);
void	d_anim_helper(t_vars *vars, void *img, int x, int y);

//MAPS.C
int check_map(char *path);
void	matrix_free(int **mat, int rows);
void	free_map(map *map);
void	error_return(int er, int fd, char *temp, char c);
void	path_valid(int **mat, int i, int j, int *path);


//WALL.C

void	list_wall(t_vars *vars, animation *wall);
void	wall_set_2(t_vars *vars, int i, int j);
box	wall_bound(t_vars *vars, int key, int i, int j);
void	wall_set(t_vars *vars);
void	wall_rend(t_vars *vars, int x, int y, int index);

//EXIT.C
void		load_exit0(t_vars *vars, animation *food);
void		load_exit1(t_vars *vars, animation *food);
animation	*exit_img(t_vars *vars);
box			exit_bound(t_vars *vars, int key, int i, int j);
void	free_portal(portal *p, t_vars *vars);


//FOOD.C
void	load_food(t_vars *vars, animation *food);
void	food_rend(t_vars *vars);
box	col_bound(t_vars *vars, int key, int i, int j);

//PLAYER.C
void	load_anim_idle(t_vars *vars, animation *sprite);
void	load_anim_run(t_vars *vars, animation *sprite);
animation	*player_img(t_vars *vars);
void	load_p1_anims(t_vars *vars);
void	load_p1(t_vars *vars);

//MATRIX.C
int	**matrix_create(int *rc, int **mat, char *path);
int	*fill_row(int *row, int fd, int lim);
int	set_r_c(int *rc, char *path);
int	check_matrix(int **mat, int row, int col);
void	check_matrix_1(int **mat, int row, int col, map_errs *err);

//ERRORS.C
void	check_errors(int *rc, int **mat);
void	malloc_er(t_vars *vars, int **mat, int *rc);

//CHECKS.C
void	game_checks(t_vars *vars);
void	mediator(char *path, int **mat, int *index, int *rc);
int	ulti_path_check(int **mat, char *path, int *start, int *rc);
void	path_valid(int **mat, int i, int j, int *path);



#endif
