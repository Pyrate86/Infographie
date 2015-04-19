/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 14:21:10 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/15 20:47:07 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

static void	draw_pixel(t_env *e, t_coord center, t_coord a, int color)
{
	mlx_pixel_put(e->mlx, e->win, center.x + a.x, center.y + a.y, color);
	mlx_pixel_put(e->mlx, e->win, center.x + a.y, center.y + a.x, color);
	mlx_pixel_put(e->mlx, e->win, center.x - a.x, center.y + a.y, color);
	mlx_pixel_put(e->mlx, e->win, center.x - a.y, center.y + a.x, color);
	mlx_pixel_put(e->mlx, e->win, center.x + a.x, center.y - a.y, color);
	mlx_pixel_put(e->mlx, e->win, center.x + a.y, center.y - a.x, color);
	mlx_pixel_put(e->mlx, e->win, center.x - a.x, center.y - a.y, color);
	mlx_pixel_put(e->mlx, e->win, center.x - a.y, center.y - a.x, color);
}

void		draw_win_circle(t_env *e, t_coord center, int r, int color)
{
	int x;
	int y;
	int d;

	x = 0;
	y = r;
	d = r - 1;
	while (y >= x)
	{
		draw_pixel(e, center, coord(x, y), color);
		if (d >= 2 * x)
			d = d - (2 * x++) - 1;
		else if (d < 2 * (r - y))
			d = d + (2 * y--) - 1;
		else
			d = d + (2 * (y-- - x++ - 1));
	}
}

static void	fill_square(t_env *e, t_coord ctr, t_coord a, int c)
{
	draw_win_hline(e, coord(ctr.x - a.x, ctr.y - a.y), ctr.x + a.x, c);
	draw_win_hline(e, coord(ctr.x - a.y, ctr.y - a.x), ctr.x + a.y, c);
	draw_win_hline(e, coord(ctr.x - a.y, ctr.y + a.x), ctr.x + a.y, c);
	draw_win_hline(e, coord(ctr.x - a.x, ctr.y + a.y), ctr.x + a.x, c);
}

void		draw_win_fcircle(t_env *e, t_coord center, int r, int color)
{
	int x;
	int y;
	int d;

	x = 0;
	y = r;
	d = r - 1;
	while (y >= x)
	{
		fill_square(e, center, coord(x, y), color);
		if (d >= 2 * x)
			d = d - (2 * x++) - 1;
		else if (d < 2 * (r - y))
			d = d + (2 * y--) - 1;
		else
			d = d + (2 * (y-- - x++ - 1));
	}
}
