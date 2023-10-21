/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmanager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:06:10 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/18 17:42:00 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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

void	add_frame_helper(t_vars *vars, char *path, animation *sprite)
{
	animation	*temp;

	temp = NULL;
	while (sprite->next)
		sprite = sprite->next;
	temp = malloc(sizeof(animation));
	if (temp == NULL)
		malloc_er(vars, NULL, NULL);
	temp->img = mlx_xpm_file_to_image(vars->mlx, path, &temp->w, &temp->h);
	sprite->next = temp;
}

void	add_frames(t_vars *vars, char *path, animation *sprite)
{
	if (!sprite->img)
		sprite->img = mlx_xpm_file_to_image(vars->mlx, path,
				&sprite->w, &sprite->h);
	else
		add_frame_helper(vars, path, sprite);
	free(path);
}
