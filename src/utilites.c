/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:03:02 by zvakil            #+#    #+#             */
/*   Updated: 2023/10/22 07:09:34 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	nuller(t_vars *vars)
{
	vars->wall = NULL;
	vars->base = NULL;
	vars->p1 = NULL;
	vars->exit = NULL;
	vars->food = NULL;
}