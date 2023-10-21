/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:03:02 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/18 17:57:14 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>
#include <stdio.h>

int press(int keycode)
{
	printf("PRESSS : %d\n", keycode);
	return(0);
}

int release(int keycode)
{
		printf("RELLES : %d\n", keycode);
	return(0);
}
int	main()
{
	void *mlx;
	void *win;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 100, 100, "ZAIN");
	mlx_hook(win, 2, 0, press, NULL);
	mlx_hook(win, 3, 0, release, NULL);
	mlx_loop(mlx);
	return (0);
}