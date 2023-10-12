#include "game.h"

// int pos_check_w(player *p1, game *wall, int pc, int pv, int key, t_vars *vars)
// {	
// 	// if my x position is from start of wall to the end of wall dont go y
// 	if (p1->y - SPEED == )
// 	return 1;
// }

int pos_check_2(int pc, int pv, int key, t_vars *vars, int *er)
{	
	
	int m_min;
	int m_max;
	int m_bd;
	int bd;
	int min;
	int max;
	int i = 0;
	int j = 0;
	while ((key == W || key == S) && i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			if (vars->map->mat[i][j] == 1)
			{
				m_min = i * vars->game->h;
				m_max = m_min + vars->game->h;
				m_bd = vars->p1->run->h;
				min = j * vars->game->w;;
				max = min + vars->game->w;;
				bd = vars->p1->run->w;
				if ((pv > m_min && pv < m_max) || (pv + m_bd > m_min && pv + m_bd < m_max))
					if ((pc > min && pc < max)
					|| (pc + bd > min && pc + bd < max)
					|| (pc + bd / 2 > min && pc + bd / 2 < max))
					{
						if (key == W)
						er[0] = m_max;
						if (key == S)
						er[0] = m_min - vars->p1->run->h;
						return 0;
					}
			}
			j++;
		}
		j = 0;
		i++;
	}
	while ((key == A || key == D) && i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			if (vars->map->mat[i][j] == 1)
			{
				m_min = j * vars->game->w;
				m_max = m_min + vars->game->w;
				m_bd = vars->p1->run->h;
				min = i * vars->game->h;
				max = min + vars->game->h;
				bd = vars->p1->run->w;
				if ((pv > m_min && pv < m_max) || (pv + m_bd > m_min && pv + m_bd < m_max))
					if ((pc > min && pc < max)
					|| (pc + bd > min && pc + bd < max)
					|| (pc + bd / 2 > min && pc + bd / 2 < max))
					{
						if (key == A)
						er[0] = m_max;
						if (key == D)
						er[0] = m_min - vars->p1->run->h;
						return 0;
					}
			}
			j++;
		}
		j = 0;
		i++;
	}	
	return 1;
}

// int pos_check_2(player *p1, game *wall, int pc, int pv, int key)
// {	
// 	int m_min;
// 	int m_max;
// 	int m_bd;
// 	int bd;
// 	int min;
// 	int max;
// 	if (key == W || key == S)
// 	{
// 		m_min = wall->y;
// 		m_max = wall->y + wall->h;
// 		m_bd = p1->run->h;
// 		min = wall->x;
// 		max = wall->x + wall->w;
// 		bd = p1->run->w;
// 	}
// 	else
// 	{
// 		m_min = wall->x;
// 		m_max = wall->x + wall->w;
// 		m_bd = p1->run->w;
// 		min = wall->y;
// 		max = wall->y + wall->h;
// 		bd = p1->run->h;
// 	}
// 		//next move check
// 		if (!(pv > m_min && pv < m_max) && !(pv + m_bd > m_min && pv + m_bd < m_max))
// 		return 1;
// 		// line limit of the collision
// 		if ((pc > min && pc < max)
// 		|| (pc + bd > min && pc + bd < max)
// 		|| (pc + bd / 2 > min && pc + bd / 2 < max))
// 		return 0;
// 	return 1;
// }

void	update_pos(int keycode, player *p1, t_vars *vars)
{
	int er[1];
	p1->move = 1; 
	if (keycode == W)
	{
		if (pos_check_2(p1->x, p1->y - SPEED, keycode, vars, er))
			p1->y -= SPEED;
		else
			p1->y = er[0];
	}
	else if (keycode == S)
	{
			if (pos_check_2(p1->x, p1->y + SPEED, keycode, vars, er))
			p1->y += SPEED;
		else
			p1->y = er[0];
	}
	else if (keycode == A)
	{
		if (pos_check_2(p1->y, p1->x - SPEED, keycode, vars, er))
			p1->x -= SPEED;
		else
			p1->x = er[0];
	}
	else if (keycode == D)
	{
		if (pos_check_2(p1->y, p1->x + SPEED, keycode, vars, er))
			p1->x += SPEED;
		else
			p1->x = er[0];
	}
}
