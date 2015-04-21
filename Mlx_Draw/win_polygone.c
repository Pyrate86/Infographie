/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_polygone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 14:27:30 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/21 14:35:19 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

static int	is_in_poly(t_coord pt, t_coord *pts, int h)
{
	t_line	a;
	t_line	b;
	int		inter;
	int		i;

	inter = 0;
	i = 0;
	a = line(pt, coord(pt.x + 1, HEIGHT));
	while (i < h)
	{
		b = line (pts[i], pts[i == h - 1 ? 0 : i + 1]);
		if (intersect(a, b) > 0)
			inter++;
		i++;
	}
	if (inter % 2 == 1)
		return (1);
	return (0);
}

void		draw_win_poly_from_pts(t_env *e, t_coord *pts, int h, int c)
{
	int	i;

	i = 0;
	while (i < h)
	{
		draw_win_line(e, pts[i], pts[i == h - 1 ? 0 : i + 1], c);
		i++;
	}
}

void		draw_win_fpoly_from_pts(t_env *e, t_coord *pts, int h, int c)
{
	int		i;
	int		y;
	t_coord	min;
	t_coord	max;

	i = 0;
	min = coord(pts[i].x, pts[i].y);
	max = coord(pts[i].x, pts[i].y);
	while (i < h)
	{
		min.x = pts[i].x < min.x ? pts[i].x : min.x;
		min.y = pts[i].y < min.y ? pts[i].y : min.y;
		max.x = pts[i].x > max.x ? pts[i].x : max.x;
		max.y = pts[i].y > max.y ? pts[i].y : max.y;
		i++;
	}
	while (min.x++ <= max.x)
	{
		y = min.y;
		while (y++ <= max.y)
		{
			if (is_in_poly(coord(min.x, y), pts, h))
				mlx_pixel_put(e->mlx, e->win, min.x, y, c);
		}
	}
}

void		draw_win_polygone(t_env *e, t_circle c, int h, int color)
{
	int		i;
	t_coord	a;
	t_coord	b;

	i = 0;
	while (i < h)
	{
		a.x = c.radius * cos(2 * M_PI * i / h - (M_PI / 2)) + c.center.x;
		a.y = c.radius * sin(2 * M_PI * i / h - (M_PI / 2)) + c.center.y;
		b.x = c.radius * cos(2 * M_PI * (i + 1) / h - (M_PI / 2)) + c.center.x;
		b.y = c.radius * sin(2 * M_PI * (i + 1) / h - (M_PI / 2)) + c.center.y;
		draw_win_line(e, a, b, color);
		i++;
	}
}

void		draw_win_fpolygone(t_env *e, t_circle c, int h, int color)
{
	int		i;
	t_coord	a;
	t_coord	b;
	t_coord *pts;

	i = 0;
	pts = (t_coord *)malloc(sizeof(t_coord) * h);
	while (i < h)
	{
		a.x = c.radius * cos(2 * M_PI * i / h - (M_PI / 2)) + c.center.x;
		a.y = c.radius * sin(2 * M_PI * i / h - (M_PI / 2)) + c.center.y;
		b.x = c.radius * cos(2 * M_PI * (i + 1) / h - (M_PI / 2)) + c.center.x;
		b.y = c.radius * sin(2 * M_PI * (i + 1) / h - (M_PI / 2)) + c.center.y;
		if (i == 0)
			pts[i] = a;
		pts[i + 1] = b;
		i++;
	}
	draw_win_fpoly_from_pts(e, pts, h, color);
}
