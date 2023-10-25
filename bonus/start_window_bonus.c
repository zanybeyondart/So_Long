// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   start_window_bonus.c                               :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/10/25 10:32:20 by zvakil            #+#    #+#             */
// /*   Updated: 2023/10/25 15:08:53 by zvakil           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "game.h"

// void	start_add_frame_helper(t_vars *vars, char *path, animation *sprite)
// {
// animation *temp;

//     temp = malloc(sizeof(animation));
//     if (temp == NULL)
//         malloc_er(vars, NULL, NULL);
//     temp->img = mlx_xpm_file_to_image(vars->start_mlx, path, &temp->w, &temp->h);
//     temp->next = NULL;
//     while (sprite->next)
//         sprite = sprite->next;
//     sprite->next = temp;
// }

// void	start_add_frames(t_vars *vars, char *path, animation *sprite)
// {
// 	if (!sprite->img)
// 		sprite->img = mlx_xpm_file_to_image(vars->start_mlx, path,
// 				&sprite->w, &sprite->h);
// 	else
// 		start_add_frame_helper(vars, path, sprite);
// 	free(path);
// }

// animation	*bg_image_helper(int frame, animation *temp)
// {
// 	int	i;

// 	i = 0;
// 	while (i < frame)
// 	{
// 		temp = temp->next;
// 		i++;
// 	}
// 	return (temp);
// }

// animation	*bg_image(animation *sprite, int frame)
// {
// 	static int	i;
// 	animation	*temp;

// 	temp = sprite;
// 	if (i >= frame - 1)
// 		i = 0;
// 	else
// 		i++;
// 	return (bg_image_helper(i, temp));
// }

// void bg_rend(t_vars *vars)
// {
// 	animation *temp;
	
// 	temp = bg_image(vars->start->bg, vars->start->bg_frame);
// 	mlx_put_image_to_window(vars->start_mlx, vars->start_win, temp->img,
// 		0, 0);
// }

// int start_callbacks(t_vars *vars)
// {
// 	usleep(100000);
// 	mlx_clear_window(vars->start_mlx, vars->start_win);
// 	bg_rend(vars);
// 	mlx_do_sync(vars->start_mlx);
// 	return (1);
// }

// void	start_free_animation(animation *anim, t_vars *vars)
// {
// 	if (anim)
// 	{
// 		start_free_animation(anim->next, vars);
// 		mlx_destroy_image(vars->start_mlx, anim->img);
// 		free(anim);
// 	}
// }

// void free_start(t_vars *vars)
// {
// 	start_free_animation(vars->start->bg, vars);
// 	free(vars->start);
// }


// void	load_anim_bg(t_vars *vars, animation *sprite)
// {
// 	static int	i;
// 	char		*path;

// 	path = NULL;
// 	while (1)
// 	{
// 		path = pather("./textures/menu/bg/bg", i, ".xpm", path);
// 		if (path == NULL)
// 		{
// 			vars->start->bg_frame = i;
// 			break ;
// 		}
// 		else
// 		{
// 			start_add_frames(vars, path, sprite);
// 			i++;
// 		}
// 	}
// }

// void load_bg(t_vars *vars)
// {
// 	vars->start->bg = malloc(sizeof(animation));
// 	vars->start->bg->img = NULL;
// 	vars->start->bg->next = NULL;
// 	load_anim_bg(vars, vars->start->bg);
// }

// void	load_start_textures(t_vars *vars)
// {
// 	vars->start = malloc(sizeof(t_menu));
// 	vars->start->bg = NULL;
// 	vars->start->logo = NULL;
// 	vars->start->o1 = NULL;
// 	vars->start->o2 = NULL;
// 	vars->start->o3 = NULL;
// 	load_bg(vars);
// }


// int keys(int keycode, t_vars *vars)
// {
// 	if (keycode == 36)
// 	{
// 		mlx_destroy_window(vars->start_mlx, vars->start_win);
// 		free_start(vars);
// 	}
// 	return(1);
// }

// int exit_v(t_vars *vars)
// {
// 	mlx_destroy_window(vars->start_mlx, vars->start_win);
// 	free_start(vars);
// 	exit(1);
// 	return 0;
// }

// void start_window(t_vars *vars)
// {
// 	vars->start_mlx = mlx_init();
// 	vars->start_win = mlx_new_window(vars->start_mlx, 780, 300, "START");
// 	load_start_textures(vars);
// 	mlx_loop_hook(vars->start_mlx, start_callbacks, vars);
// 	mlx_hook(vars->start_win, 2, 0 ,keys, vars);
// 	mlx_hook(vars->start_win, 17, 0, exit_v, vars);
// 	mlx_loop(vars->start_mlx);
// }