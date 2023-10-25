/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:29:07 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/25 18:00:38 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H

# include "../mlx/mlx.h"
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
# define V 38

typedef struct frames{
	void			*img;
	int				w;
	int				h;
	struct frames	*next;
} animation;

typedef struct list
{
	animation *idle;
	animation *idle_l;
	animation *run;
	animation *run_l;
	animation *active;
	int run_frames;
	int idle_frames;
	int x;
	int y;
	int move;
	int move_count;
	int dir;
}player;

typedef struct s_enem_info
{
	int x;
	int y;
	int dir;
	int r_wall;
	int l_wall;
	int alive;
	animation *right_anim;
	animation *left_anim;
	animation *active;
	int frames;
	struct s_enem_info *next;	
}t_enem_info;

typedef struct portal
{
	animation *disabled;
	animation *enabled;
	animation *active;
	int exit_dis_frame;
	int exit_en_frame;
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

typedef struct s_kill
{
	animation *anim;
	int x;
	int y;
	int spawn;
	int frames;
}t_kill;

typedef struct s_power
{
	animation *anim;
	animation *anim_l;
	int x;
	int y;
	int spawn;
	int frames;
}t_power;

typedef struct s_menu
{
	animation *bg;
	int bg_frame;
	animation *logo;
	int logo_frame;
	animation *o1;
	int o1_frame;
	animation *o2;
	int o2_frame;
	animation *o3;
	int o3_frame;
}t_menu;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void 	*start_mlx;
	void	*start_win;
	player	*p1;
	map *map;
	animation *wall;
	animation *food;
	animation	*base;
	portal *exit;
	t_enem_info *enemies;
	t_power *power;
	t_kill *kill;
	t_menu *start_screen;
	t_menu *end_screen;
	int game_state;
	int end;
} t_vars;

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

typedef struct map{
	int w;
	int c;
	int p;
	int e;
	int xtra;
} map_errs;



// MAIN.C
void load_power(t_vars *vars);
void enemy_updates(t_enem_info *enemy, t_vars *vars);
int quit(t_vars *vars);
int events(int keycode, t_vars *vars);
int callbacks(t_vars *vars);
int	game_start(int **mat, int *rc);


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
animation	*image(animation *sprite, int frame);
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
void load_anim_enemy_right(t_vars *vars, animation *sprite);
void load_anim_enemy_left(t_vars *vars, animation *sprite);
void	enemies_rend(t_vars *vars, t_enem_info *enemy);
void	enemies_list_send(t_vars *vars);
void power_rend(t_vars *vars);
void	exit_rend(t_vars *vars);

//FOOD.C
void	load_food(t_vars *vars);
void	food_rend(t_vars *vars);
box	col_bound(t_vars *vars, int key, int i, int j);
void load_kill(t_vars *vars);
void kill_rend(t_vars *vars);
//PLAYER.C
void	load_anim_idle(t_vars *vars, animation *sprite);
void	load_anim_run(t_vars *vars, animation *sprite);
animation	*player_img(t_vars *vars);
void	load_p1(t_vars *vars);
void	nuller(t_vars *vars);

void	enemy_list(t_vars *vars, t_enem_info *enemies, int i, int j);
int enemy_wall_col(t_vars *vars, int i, int j, int dir);
void	game_state_2_render(t_vars *vars);
void	game_state_2_keys(int keycode, t_vars *vars);
void	load_p1_anims_idle_assign(t_vars *vars);
void	load_p1_anims_run_assign(t_vars *vars);
void	load_p1_anims_run_assign(t_vars *vars);
void	load_anim_idle(t_vars *vars, animation *sprite);
void	load_anim_idle_2(t_vars *vars, animation *sprite);
void	load_anim_run(t_vars *vars, animation *sprite);
void	load_anim_run_2(t_vars *vars, animation *sprite);

//MATRIX.C
int	**matrix_create(int *rc, int **mat, char *path);
int	*fill_row(int *row, int fd, int lim);
int	set_r_c(int *rc, char *path);
int	check_matrix(int **mat, int row, int col);
void	check_matrix_1(int **mat, int row, int col, map_errs *err);

//ERRORS.C
void	check_errors(int *rc, int **mat);
void	malloc_er(t_vars *vars, int **mat, int *rc);
void start_window(t_vars *vars);

//CHECKS.C
void	game_checks(t_vars *vars);
void	mediator(char *path, int **mat, int *index, int *rc);
int	ulti_path_check(int **mat, char *path, int *start, int *rc);
void	path_valid(int **mat, int i, int j, int *path);
void	load_enemies(t_vars *vars);
void	load_enemy_anims(t_vars *vars);
void power_updates(t_vars *vars);
box	power_bound(t_vars *vars, int i, int j);
int	power_check_inter(box temp, int pv, int pc, t_vars *vars);
int	lim(int a, int b, int c);
void power_check(t_vars *vars);
animation	*exit_image_helper(int frame, animation *temp);
void	load_anim_idle_2(t_vars *vars, animation *sprite);
#endif
