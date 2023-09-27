#include "game.h"

// int pos_check_2(player *p1, game *wall)
// {	
// 	if ((p1->x > wall->x && p1->x < wall->x + wall->w)
// 	&& (p1->x + p1->run->w > wall->x && p1->x + p1->run->w < wall->x + wall->w)
// 	&& )
// 	return 0;
// 	if ((p1->y - SPEED > wall->y && p1->y - SPEED < wall->y + wall->h) && (p1->y + p1->run->h - SPEED> wall->y && p1->y + p1->run->h - SPEED < wall->y + wall->h) )
// 	return 0;
// 	return 1;

// }

// int pos_check(int key, player *p1, game *wall, t_vars *vars)
// {
// 	if (key == W)
// 	{
// 	if(pos_check_2(p1, wall, p1->x, p1->y - SPEED, key))
// 	return(1);
// 	}
// 	if (key == S)
// 	{
// 	if(pos_check_2(p1, wall, p1->x, p1->y + SPEED, key))
// 	return(1);
// 	}
// 	if (key == D)
// 	{
// 		if(pos_check_2(p1, wall, p1->y, p1->x + SPEED, key))
// 		return(1);
// 	}
// 	if (key == A)
// 	if(pos_check_2(p1, wall, p1->y, p1->x - SPEED, key))
// 	return(1);
// 	return (0);
// }

int pos_check_2(player *p1, game *wall, int pc, int pv, int key)
{	
	int m_min;
	int m_max;
	int m_bd;
	int bd;
	int min;
	int max;
	if (key == W || key == S)
	{
		m_min = wall->y;
		m_max = wall->y + wall->h;
		m_bd = p1->run->h;
		min = wall->x;
		max = wall->x + wall->w;
		bd = p1->run->w;
	}
	else
	{
		m_min = wall->x;
		m_max = wall->x + wall->w;
		m_bd = p1->run->w;
		min = wall->y;
		max = wall->y + wall->h;
		bd = p1->run->h;
	}
		//next move check
		if (!(pv > m_min && pv < m_max) && !(pv + m_bd > m_min && pv + m_bd < m_max))
		return 1;
		// line limit of the collision
		if ((pc > min && pc < max)
		|| (pc + bd > min && pc + bd < max)
		|| (pc + bd / 2 > min && pc + bd / 2 < max))
		return 0;
	return 1;
}

void	update_pos(int keycode, player *p1, t_vars *vars)
{
	if (keycode == W)
	{
		if (pos_check_2(p1, vars->game, p1->x, p1->y - SPEED, keycode))
			p1->y -= SPEED;
		else
			p1->y = vars->game->y + vars->game->h;
	p1->move = 1; 

	}
	else if (keycode == S)
	{
			if (pos_check_2(p1, vars->game, p1->x, p1->y + SPEED, keycode))
			p1->y += SPEED;
		else
			p1->y = vars->game->y - p1->run->h;
	p1->move = 1; 
	}
	else if (keycode == A)
	{
		if (pos_check_2(p1, vars->game, p1->y, p1->x - SPEED, keycode))
			p1->x -= SPEED;
		else
			p1->x = vars->game->x + vars->game->w;
	p1->move = 1; 
	}
	else if (keycode == D)
	{
		if (pos_check_2(p1, vars->game, p1->y, p1->x + SPEED, keycode))
			p1->x += SPEED;
		else
			p1->x = vars->game->x - p1->run->w;
	p1->move = 1; 
	}
}
