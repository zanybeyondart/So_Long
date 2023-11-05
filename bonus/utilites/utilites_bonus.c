/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:03:02 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/05 05:39:36 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_bonus.h"

void	nuller(t_vars *vars)
{
	vars->p1 = NULL;
	vars->wall = NULL;
	vars->base = NULL;
	vars->exit = NULL;
	vars->food = NULL;
	vars->enemies = NULL;
	vars->power = NULL;
	vars->kill = NULL;
	vars->number = NULL;
	vars->start_screen = NULL;
	vars->cursor = NULL;
	vars->easteregg_screen = NULL;
	vars->end_lose_screen = NULL;
	vars->end_win_screen = NULL;
	vars->power = NULL;
	vars->pause_screen = NULL;
	vars->easteregg_text = NULL;
}

char	*pather(char *main, int frame, char *ext, char *path)
{
	int	index0;
	int	index1;
	int	fd;

	path = malloc(ft_strlen(main) + ft_strlen(ext) + 2);
	index0 = 0;
	index1 = 0;
	while (main[index0] != '\0')
		path[index1++] = main[index0++];
	index0 = 0;
	path[index1++] = frame + '0';
	while (ext[index0] != '\0')
		path[index1++] = ext[index0++];
	path[index1] = '\0';
	fd = open(path, O_RDONLY);
	if (fd < 0 && path != NULL)
	{
		free(path);
		return (NULL);
	}
	else
	{
		close(fd);
		return (path);
	}
}

void	add_frame_helper(t_vars *vars, char *path, t_animation *sprite)
{
	t_animation	*temp;

	temp = malloc(sizeof(t_animation));
	if (temp == NULL)
		malloc_er(vars, NULL, NULL);
	temp->img = mlx_xpm_file_to_image(vars->mlx, path, &temp->w, &temp->h);
	temp->next = NULL;
	while (sprite->next)
		sprite = sprite->next;
	sprite->next = temp;
}

void	add_frames(t_vars *vars, char *path, t_animation *sprite)
{
	if (!sprite->img)
		sprite->img = mlx_xpm_file_to_image(vars->mlx, path,
				&sprite->w, &sprite->h);
	else
		add_frame_helper(vars, path, sprite);
	free(path);
}

int	quit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_vars(vars);
	exit(1);
}
