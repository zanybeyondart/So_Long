/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:29:07 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/27 14:22:02 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_BONUS_H

# define GAME_BONUS_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <strings.h>
# include "../get_next_line/get_next_line.h"
# include "../printf/ft_printf.h"

# define SPEED	15
# define W	126
# define A	123
# define S	125
# define D	124
# define P 32
# define C 19
# define E 21
# define V 38

typedef struct s_animation{
	void				*img;
	int					w;
	int					h;
	struct s_animation	*next;
}t_animation;

typedef struct s_player
{
	t_animation	*idle;
	t_animation	*idle_l;
	t_animation	*run;
	t_animation	*run_l;
	t_animation	*active;
	t_animation	*death_r;
	t_animation	*death_l;
	t_animation	*win_r;
	t_animation	*win_l;
	int			run_frames;
	int			idle_frames;
	int			x;
	int			y;
	int			move;
	int			move_count;
	int			dir;
}t_player;

typedef struct s_enem_info
{
	int					x;
	int					y;
	int					dir;
	int					r_wall;
	int					l_wall;
	int					alive;
	t_animation			*right_anim;
	t_animation			*left_anim;
	t_animation			*active;
	int					frames;
	struct s_enem_info	*next;	
}t_enem_info;

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

typedef struct s_kill
{
	t_animation	*anim;
	int			x;
	int			y;
	int			spawn;
	int			frames;
}t_kill;

typedef struct s_power
{
	t_animation	*anim;
	t_animation	*anim_l;
	int			x;
	int			y;
	int			spawn;
	int			frames;
}t_power;

typedef struct s_menu
{
	t_animation	*o1;
	t_animation	*o2;
	t_animation	*o3;
	t_animation	*o4;
	int			frame;
	int			option;
}t_menu;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_player	*p1;
	t_map		*map;
	t_animation	*wall;
	t_animation	*food;
	t_animation	*base;
	t_portal	*exit;
	t_enem_info	*enemies;
	t_power		*power;
	t_kill		*kill;
	t_menu		*start_screen;
	t_menu		*pause_screen;
	t_menu		*end_win_screen;
	t_menu		*end_lose_screen;
	t_menu		*easteregg_screen;
	t_animation	*easteregg_text;
	t_animation	*number;
	t_animation	*cursor;
	int			cursor_frame;
	int			cursor_x;
	int			cursor_y;
	int			game_state;
}t_vars;

typedef struct s_box
{
	int	m_min;
	int	m_max;
	int	m_bd;
	int	bd;
	int	min;
	int	max;
}t_box;

typedef struct s_map_err{
	int	w;
	int	c;
	int	p;
	int	e;
	int	xtra;
}t_map_err;

t_animation	*image_helper(int frame, t_animation *temp);
t_animation	*image(t_animation *sprite, int frame);
t_animation	*exit_image_helper(int frame, t_animation *temp);
t_animation	*exit_image(t_animation *sprite, int frame);
t_animation	*exit_img(t_vars *vars);
t_animation	*player_img(t_vars *vars);
t_animation	*en_image_helper(int frame, t_animation *temp);
t_animation	*en_image(t_animation *sprite, int frame);
t_animation	*kill_image(t_animation *sprite, int frame, t_vars *vars);
t_animation	*kill_image_helper(int frame, t_animation *temp);
t_animation	*pow_image_helper(int frame, t_animation *temp);
t_animation	*pow_image(t_animation *sprite, int frame);
t_animation	*number(t_vars *vars, int pos);
t_animation	*menu_image_helper(int frame, t_animation *temp);
t_animation	*menu_image(t_animation *sprite, int frame);
t_animation	*pmenu_image_helper(int frame, t_animation *temp);
t_animation	*pmenu_image(t_animation *sprite, int frame);
t_animation	*el_menu_image_helper(int frame, t_animation *temp);
t_animation	*el_menu_image(t_animation *sprite, int frame);
t_animation	*ew_menu_image_helper(int frame, t_animation *temp);
t_animation	*ew_menu_image(t_animation *sprite, int frame);
t_box		wall_bound(t_vars *vars, int key, int i, int j);
t_box		col_bound(t_vars *vars, int key, int i, int j);
t_box		exit_bound(t_vars *vars, int key, int i, int j);
t_box		en_bound(t_vars *vars, t_enem_info *enemy);
t_box		power_bound(t_vars *vars, int i, int j);
int			power_check_inter(t_box temp, int pv, int pc, t_vars *vars);
int			easter_egg(int button, int x, int y, t_vars *vars);
int			mouse_move(int x, int y, t_vars *vars);
int			enemy_wall_col(t_vars *vars, int i, int j, int dir);
int			en_check_inter(t_box temp, int pv, int pc);
int			win_rend(t_vars *vars, t_animation *temp, int x, int y);
int			death_rend(t_vars *vars, t_animation *temp, int x, int y);
int			check_map(char *path);
int			main(int ac, char **av);
int			check_valid_alpha(char c);
int			ulti_path_check(int **mat, char *path, int *start, int *rc);
int			check_matrix(int **mat, int row, int col);
int			set_r_c(int *rc, char *path);
int			*fill_row(int *row, int fd, int lim);
int			**matrix_create(int *rc, int **mat, char *path);
int			quit(t_vars *vars);
int			easteregg_found(t_vars *vars, t_animation *temp);
int			events(int keycode, t_vars *vars);
int			callbacks(t_vars *vars);
int			on_release(int keycode, t_vars *vars);
int			game_start(int **mat, int *rc);
int			lim(int a, int b, int c);
int			check_inter(t_box temp, int pv, int pc);
int			pos_check_1(int pc, int pv, int key, t_vars *vars);
int			loadplayers(t_vars *vars);
void		update_pos(int keycode, t_player *p1, t_vars *vars);
void		main_display(t_vars *vars);
void		load_wall(t_vars *vars);
void		load_base(t_vars *vars);
void		wall_set_2(t_vars *vars, int i, int j);
void		list_wall(t_vars *vars, t_animation *wall);
void		wall_rend(t_vars *vars, int x, int y, int index);
void		list_food(t_vars *vars, t_animation *food);
void		load_food(t_vars *vars);
void		food_rend(t_vars *vars);
void		wall_set(t_vars *vars);
void		check_matrix_1(int **mat, int row, int col, t_map_err *err);
void		check_errors(int *rc, int **mat);
void		malloc_er(t_vars *vars, int **mat, int *rc);
void		game_checks(t_vars *vars);
void		mediator(char *path, int **mat, int *index, int *rc);
void		path_valid(int **mat, int i, int j, int *path);
void		free_enemies(t_enem_info *enemies, t_vars *vars);
void		free_power(t_power *power, t_vars *vars);
void		free_kill(t_kill *kill, t_vars *vars);
void		free_vars(t_vars *vars);
void		free_menu(t_menu *menu, t_vars *vars);
void		free_animation(t_animation *anim, t_vars *vars);
void		free_player(t_player *p, t_vars *vars);
void		free_portal(t_portal *p, t_vars *vars);
void		restart_enemy_list(t_vars *vars, t_enem_info *temp, int i, int j);
void		reset_pec(t_vars *vars);
void		restart_enemy(t_vars *vars);
void		restart_game(t_vars *vars);
void		nuller(t_vars *vars);
void		add_frame_helper(t_vars *vars, char *path, t_animation *sprite);
void		add_frames(t_vars *vars, char *path, t_animation *sprite);
void		load_exit(t_vars *vars);
void		load_exit0(t_vars *vars, t_animation *food);
void		load_exit1(t_vars *vars, t_animation *food);
void		load_exit_en_dis(t_vars *vars);
void		exit_rend(t_vars *vars);
void		error_return(int er, int fd, char *temp, char c);
void		matrix_free(int **mat, int rows);
void		free_map(t_map *map);
void		p1_nulls(t_vars *vars);
void		load_p1(t_vars *vars);
void		load_p1_anims_idle_assign(t_vars *vars);
void		load_p1_anims_run_assign(t_vars *vars);
void		load_anim_idle(t_vars *vars, t_animation *sprite);
void		load_anim_idle_2(t_vars *vars, t_animation *sprite);
void		load_anim_run(t_vars *vars, t_animation *sprite);
void		load_anim_run_2(t_vars *vars, t_animation *sprite);
void		player_rend(t_vars *vars);
void		death_seq(t_vars *vars);
void		load_p1_anims_death_assign(t_vars *vars);
void		load_anim_death(t_vars *vars, t_animation *sprite);
void		load_anim_death_2(t_vars *vars, t_animation *sprite);
void		win_seq(t_vars *vars);
void		load_anim_win(t_vars *vars, t_animation *sprite);
void		load_anim_win_2(t_vars *vars, t_animation *sprite);
void		load_p1_anims_win_assign(t_vars *vars);
void		enemy_updates(t_enem_info *enemy, t_vars *vars);
void		load_enemies_head(t_vars *vars, int i, int j);
void		load_enemies(t_vars *vars);
void		load_enemy_anims(t_vars *vars);
void		enemy_list(t_vars *vars, t_enem_info *enemies, int i, int j);
void		load_anim_enemy_right(t_vars *vars, t_animation *sprite);
void		load_anim_enemy_left(t_vars *vars, t_animation *sprite);
void		enemies_rend(t_vars *vars, t_enem_info *enemy);
void		enemies_list_send(t_vars *vars);
void		power_updates(t_vars *vars);
void		power_check(t_vars *vars);
void		load_anim_kill(t_vars *vars, t_animation *sprite);
void		load_kill(t_vars *vars);
void		kill_rend(t_vars *vars);
void		power_rend(t_vars *vars);
void		load_anim_power_2(t_vars *vars, t_animation *sprite);
void		load_anim_power(t_vars *vars, t_animation *sprite);
void		load_power(t_vars *vars);
void		game_state_2_render(t_vars *vars);
void		game_state_2_keys(int keycode, t_vars *vars);
void		moves_rend(t_vars *vars);
void		load_numbers(t_vars *vars, t_animation *sprite);
void		moves_loader(t_vars *vars);
void		game_state_nav_keys(int keycode, t_vars *vars);
void		game_state_en_esc_keys(int keycode, t_vars *vars);
void		game_state_1_keys(int keycode, t_vars *vars);
void		load_start_anims(t_vars *vars);
void		load_screen_1(t_vars *vars);
void		load_o1(t_vars *vars, t_animation *sprite);
void		load_o2(t_vars *vars, t_animation *sprite);
void		load_o3(t_vars *vars, t_animation *sprite);
void		load_o4(t_vars *vars, t_animation *sprite);
void		game_state_1_render(t_vars *vars);
void		game_state3_nav_keys(int keycode, t_vars *vars);
void		game_state3_en_esc_keys(int keycode, t_vars *vars);
void		game_state_3_keys(int keycode, t_vars *vars);
void		load_pause_anims(t_vars *vars);
void		load_screen_3(t_vars *vars);
void		load_pause_o1(t_vars *vars, t_animation *sprite);
void		load_pause_o2(t_vars *vars, t_animation *sprite);
void		load_pause_o3(t_vars *vars, t_animation *sprite);
void		load_pause_o4(t_vars *vars, t_animation *sprite);
void		game_state_3_render(t_vars *vars);
void		game_state4_nav_keys(t_vars *vars);
void		game_state4_en_esc_keys(int keycode, t_vars *vars);
void		game_state_4_keys(int keycode, t_vars *vars);
void		load_end_win_anims(t_vars *vars);
void		load_screen_4(t_vars *vars);
void		load_end_win_o1(t_vars *vars, t_animation *sprite);
void		load_end_win_o2(t_vars *vars, t_animation *sprite);
void		load_end_win_o3(t_vars *vars, t_animation *sprite);
void		load_end_win_o4(t_vars *vars, t_animation *sprite);
void		game_state_4_render(t_vars *vars);
void		game_state5_nav_keys(t_vars *vars);
void		game_state5_en_esc_keys(int keycode, t_vars *vars);
void		game_state_5_keys(int keycode, t_vars *vars);
void		load_end_lose_anims(t_vars *vars);
void		load_screen_5(t_vars *vars);
void		load_end_lose_o1(t_vars *vars, t_animation *sprite);
void		load_end_lose_o2(t_vars *vars, t_animation *sprite);
void		load_end_lose_o3(t_vars *vars, t_animation *sprite);
void		load_end_lose_o4(t_vars *vars, t_animation *sprite);
void		game_state_5_render(t_vars *vars);
void		load_easteregg_anims(t_vars *vars);
void		load_screen_6(t_vars *vars);
void		load_easteregg_o1(t_vars *vars, t_animation *sprite);
void		load_easteregg_o2(t_vars *vars, t_animation *sprite);
void		game_state_6_render(t_vars *vars);
void		load_cursor(t_vars *vars, t_animation *sprite);
void		load_easteregg_text(t_vars *vars, t_animation *sprite);
char		*pather(char *main, int frame, char *ext, char *path);

#endif
