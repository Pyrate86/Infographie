/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 10:46:51 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/12 10:46:59 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_bg(t_env *e)
{
	int start;
	int end;

	e->x = 0;
	while (e->x < WIDTH)
	{
		start = 0;
		end = HEIGHT / 2;
		e->color = 0x007FFF;
		drawcf(e, start, end);
		start = HEIGHT / 2;
		end = HEIGHT;
		e->color = 0x509900;
		drawcf(e, start, end);
		e->x++;
	}
}

void	right(t_env *e)
{
	double		olddirx;
	double		oldplanex;

	olddirx = e->dirx;
	e->dirx = e->dirx * cos(RS) - e->diry * sin(RS);
	e->diry = olddirx * sin(RS) + e->diry * cos(RS);
	oldplanex = e->planx;
	e->planx = e->planx * cos(RS) - e->plany * sin(RS);
	e->plany = oldplanex * sin(RS) + e->plany * cos(RS);
}

void	left(t_env *e)
{
	double		olddirx;
	double		oldplanex;

	olddirx = e->dirx;
	e->dirx = e->dirx * cos(-RS) - e->diry * sin(-RS);
	e->diry = olddirx * sin(-RS) + e->diry * cos(-RS);
	oldplanex = e->planx;
	e->planx = e->planx * cos(-RS) - e->plany * sin(-RS);
	e->plany = oldplanex * sin(-RS) + e->plany * cos(-RS);
}

void	down(t_env *e)
{
	if (e->map[(int)(e->posy - e->diry * MS)][(int)(e->posx)] == 32)
		e->posy -= e->diry * MS;
	if (e->map[(int)(e->posy)][(int)(e->posx - e->dirx * MS)] == 32)
		e->posx -= e->dirx * MS;
}

void	up(t_env *e)
{
	if (e->map[(int)(e->posy + e->diry * MS)][(int)(e->posx)] == 32)
		e->posy += e->diry * MS;
	if (e->map[(int)(e->posy)][(int)(e->posx + e->dirx * MS)] == 32)
		e->posx += e->dirx * MS;
}
