/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 04:13:51 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/30 04:14:01 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	third_dim(t_env *e, t_coord a, int z)
{
	a.y -= (z * e->tile_size) / e->height;
	return (a);
}

static t_coord	iso(t_env *e, t_coord a, int z)
{
	t_coord	p;

	p.x = (a.x - a.y) + e->interval.x;
	p.y = (a.x + a.y) / 2 + e->interval.y;
	p = third_dim (e, p, z);
	return (p);
}

static void		drawpt(t_env *e, int x, int y)
{
	t_coord	a;
	t_coord	b;
	int		h;

	a.x = x * e->tile_size;
	a.y = y * e->tile_size;
	b.x = (x - 1) * e->tile_size;
	b.y = y * e->tile_size;
	h = e->map[y][x] < e->map[y][x - 1] ? e->map[y][x - 1] : e->map[y][x];
	h = ((double)h / (double)(e->max - e->min)) * 200;
	a = iso(e, a, e->map[y][x]);
	if (x > 1)
	{
		b = iso(e, b, e->map[y][x - 1]);
		drawline(e->img, a, b, h);
	}
	if (y > 1 && x <= e->map[y - 1][0])
	{
		b.x = x * e->tile_size;
		b.y = (y - 1) * e->tile_size;
		b = iso(e, b, e->map[y - 1][x]);
		h = e->map[y][x] < e->map[y - 1][x] ? e->map[y - 1][x] : e->map[y][x];
		h = ((double)h / (double)(e->max - e->min)) * 200;
		drawline(e->img, a, b, h);
	}
}

void			fdf(t_env *e)
{
	int		x;
	int		y;

	if (e->getmap == 0)
	{
		get_map(e);
		e->getmap = 1;
	}
	y = 1;
	while (y < e->maph)
	{
		x = 1;
		while (x <= e->map[y][0])
		{
			drawpt(e, x, y);
			x++;
		}
		y++;
	}
}
