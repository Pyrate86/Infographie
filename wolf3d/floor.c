/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 04:14:08 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/17 04:14:20 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	nyarlathotep(t_env *e, double curfx, double curfy, int end)
{
	t_coord	ftex;
	t_coord	pos;
	int		pxl;
	int		i;

	ftex.x = (int)(curfx * 64) % 64;
	ftex.y = (int)(curfy * 64) % 64;
	pos.x = e->t_posx * 64;
	pos.y = e->t_posy * 64;
	pxl = (ftex.x + pos.x) * (e->t_bpp / 8) + (ftex.y + pos.y) * e->t_sl;
	i = e->x * (e->bpp / 8) + end * e->sl;
	e->data[i] = e->t_data[pxl];
	e->data[i + 1] = e->t_data[pxl + 1];
	e->data[i + 2] = e->t_data[pxl + 2];
}

void	cthulhu(t_env *e, double floorx, double floory, int drawend)
{
	double	weight;
	double	curfloorx;
	double	curfloory;
	double	currdist;

	currdist = (double)HEIGHT / (double)(2.0 * drawend - HEIGHT);
	weight = currdist / e->wallh;
	curfloorx = weight * floorx + (1.0 - weight) * e->posx;
	curfloory = weight * floory + (1.0 - weight) * e->posy;
	nyarlathotep(e, curfloorx, curfloory, drawend);
}

void	draw_floor(t_env *e)
{
	double	floorx;
	double	floory;
	int		drawend;

	drawend = e->lineheight / 2 + HEIGHT / 2 + 1;
	if (e->side < 2)
	{
		floorx = e->rdirx > 0 ? e->mapx : e->mapx + 1.0;
		floory = e->mapy + e->t_wallx;
	}
	else if (e->side > 1)
	{
		floorx = e->mapx + e->t_wallx;
		floory = e->rdiry > 0 ? e->mapy : e->mapy + 1.0;
	}
	while (drawend < HEIGHT)
	{
		cthulhu(e, floorx, floory, drawend);
		drawend++;
	}
}
