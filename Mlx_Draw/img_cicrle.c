/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_cicrle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 13:28:29 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/20 17:16:04 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

static void	draw_cpixel(void *img_ptr, t_coord center, t_coord a, int color)
{
	draw_pixel(img_ptr, center.x + a.x, center.y + a.y, color);
	draw_pixel(img_ptr, center.x + a.y, center.y + a.x, color);
	draw_pixel(img_ptr, center.x - a.x, center.y + a.y, color);
	draw_pixel(img_ptr, center.x - a.y, center.y + a.x, color);
	draw_pixel(img_ptr, center.x + a.x, center.y - a.y, color);
	draw_pixel(img_ptr, center.x + a.y, center.y - a.x, color);
	draw_pixel(img_ptr, center.x - a.x, center.y - a.y, color);
	draw_pixel(img_ptr, center.x - a.y, center.y - a.x, color);
}

void		draw_circle(void *img_ptr, t_circle c, int color)
{
	int x;
	int y;
	int d;

	x = 0;
	y = c.radius;
	d = c.radius - 1;
	while (y >= x)
	{
		draw_cpixel(img_ptr, c.center, coord(x, y), color);
		if (d >= 2 * x)
			d = d - (2 * x++) - 1;
		else if (d < 2 * (c.radius - y))
			d = d + (2 * y--) - 1;
		else
			d = d + (2 * (y-- - x++ - 1));
	}
}

static void	fill_square(void *img, t_coord center, t_coord a, int c)
{
	draw_hline(img, coord(center.x - a.x, center.y - a.y), center.x + a.x, c);
	draw_hline(img, coord(center.x - a.y, center.y - a.x), center.x + a.y, c);
	draw_hline(img, coord(center.x - a.y, center.y + a.x), center.x + a.y, c);
	draw_hline(img, coord(center.x - a.x, center.y + a.y), center.x + a.x, c);
}

void		draw_fcircle(void *img_ptr, t_circle c, int color)
{
	int x;
	int y;
	int d;

	x = 0;
	y = c.radius;
	d = c.radius - 1;
	while (y >= x)
	{
		fill_square(img_ptr, c.center, coord(x, y), color);
		if (d >= 2 * x)
			d = d - (2 * x++) - 1;
		else if (d < 2 * (c.radius - y))
			d = d + (2 * y--) - 1;
		else
			d = d + (2 * (y-- - x++ - 1));
	}
}
