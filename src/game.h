/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:29:07 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/05 10:06:42 by zvakil           ###   ########.fr       */
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
# include "../printf/ft_printf.h"

# define SPEED	15
# define W	13
# define A	0
# define S	1
# define D	2
# define P 32
# define C 19
# define E 21

typedef struct s_animation{
	void				*img;
	int					w;
	int					h;
	struct s_animation	*next;
}t_animation;

typedef struct s_player
{
	t_animation	*idle;
	t_animation	*run;
	t_animation	*active;
	int			run_frames;
	int			idle_frames;
	int			x;
	int			y;
	int			move;
	int			move_count;
}t_player;

typedef struct s_portal
{
	t_animation	*disabled;
	t_animation	*enabled;
	t_animation	*active;
	int			exit_dis_frame;
	int			exit_en_frame;
	int			x;
	int			y;
	int			exit;
}t_portal;

typedef struct s_map
{
	int	**mat;
	int	*rc;
}t_map;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_player	*p1;
	t_map		*map;
	t_animation	*wall;
	t_animation	*food;
	t_animation	*base;
	t_portal	*exit;
	int			end;
}t_vars;

typedef struct s_box
{
	int	pv;
	int	pc;
	int	m_min;
	int	m_max;
	int	m_bd;
	int	bd;
	int	min;
	int	max;
	int	er;
}t_box;

typedef struct s_map_errs{
	int	w;
	int	c;
	int	p;
	int	e;
	int	xtra;
}t_map_errs;

t_animation	*image_helper(int frame, t_animation *temp);
t_animation	*image(t_animation *sprite, int frame);
t_animation	*exit_img(t_vars *vars);
t_animation	*player_img(t_vars *vars);
void		free_animation(t_animation *anim, t_vars *vars);
void		free_player(t_player *p, t_vars *vars);
void		free_vars(t_vars *vars);
void		update_pos(int keycode, t_player *p1, t_vars *vars);
void		load_exit_en_dis(t_vars *vars);
void		load_exit(t_vars *vars);
void		load_wall(t_vars *vars);
void		load_base(t_vars *vars);
void		add_frames(t_vars *vars, char *path, t_animation *sprite);
void		add_frame_helper(t_vars *vars, char *path, t_animation *sprite);
void		d_anim_helper(t_vars *vars, void *img, int x, int y);
void		matrix_free(int **mat, int rows);
void		free_map(t_map *map);
void		error_return(int er, int fd, char *temp, char c);
void		list_wall(t_vars *vars, t_animation *wall);
void		wall_set_2(t_vars *vars, int i, int j);
void		wall_set(t_vars *vars);
void		wall_rend(t_vars *vars, int x, int y, int index);
int			char_check(int c);
void		load_exit0(t_vars *vars, t_animation *food);
void		load_exit1(t_vars *vars, t_animation *food);
void		free_portal(t_portal *p, t_vars *vars);
void		load_food(t_vars *vars, t_animation *food);
void		food_rend(t_vars *vars);
void		load_anim_idle(t_vars *vars, t_animation *sprite);
void		load_anim_run(t_vars *vars, t_animation *sprite);
void		load_p1_anims(t_vars *vars);
void		load_p1(t_vars *vars);
void		nuller(t_vars *vars);
void		check_matrix_1(int **mat, int row, int col, t_map_errs *err);
void		check_errors(int *rc, int **mat);
void		malloc_er(t_vars *vars, int **mat, int *rc);
void		game_checks(t_vars *vars);
void		mediator(char *path, int **mat, int *index, int *rc);
void		path_valid(t_map *mat, int i, int j, int *path);
void		main_display(t_vars *vars);
char		*pather(char *main, int frame, char *ext, char *path);
t_box		wall_bound(t_vars *vars, int key, int i, int j);
t_box		exit_bound(t_vars *vars, int key, int i, int j);
t_box		col_bound(t_vars *vars, int key, int i, int j);
int			quit(t_vars *vars);
int			events(int keycode, t_vars *vars);
int			callbacks(t_vars *vars);
int			game_start(int **mat, int *rc);
int			pos_check_1(int pc, int pv, int key, t_vars *vars);
int			loadplayers(t_vars *vars);
int			check_map(char *path, int i);
int			**matrix_create(int *rc, int **mat, char *path);
int			*fill_row(int *row, int fd, int lim);
int			set_r_c(int *rc, char *path);
int			check_matrix(int **mat, int row, int col);
int			ulti_path_check(int **mat, char *path, int *start, int *rc);

#endif