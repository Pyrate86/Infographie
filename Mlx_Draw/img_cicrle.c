/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_cicrle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 13:28:29 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/15 14:26:11 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

static void	draw_pixel(void *img_ptr, t_coord center, t_coord a, int color)
{
	mlx_pixel_put_img(img_ptr, center.x + a.x , center.y + a.y, color);
	mlx_pixel_put_img(img_ptr, center.x + a.y , center.y + a.x, color);
	mlx_pixel_put_img(img_ptr, center.x - a.x , center.y + a.y, color);
	mlx_pixel_put_img(img_ptr, center.x - a.y , center.y + a.x, color);
	mlx_pixel_put_img(img_ptr, center.x + a.x , center.y - a.y, color);
	mlx_pixel_put_img(img_ptr, center.x + a.y , center.y - a.x, color);
	mlx_pixel_put_img(img_ptr, center.x - a.x , center.y - a.y, color);
	mlx_pixel_put_img(img_ptr, center.x - a.y , center.y - a.x, color);
}

void	draw_circle(void *img_ptr, t_coord center, int r, int color)
{
	int x;
	int y;
	int d;

	x = 0;
	y = r;
	d = r - 1;
	while (y >= x)
	{
		draw_pixel(img_ptr, center, coord(x, y), color);
		if (d >= 2 * x)
			d = d -( 2 * x++) - 1;
		else if ( d < 2 * (r - y))
			d = d + ( 2 * y--) - 1;
		else
			d = d + (2 * (y-- - x++ - 1));
	}
}

static void	fill_square(void *img_ptr, t_coord center, t_coord a, int color)
{
	draw_hline(img_ptr, coord(center.x - a.x, center.y - a.y), center.x + a.x, color);
	draw_hline(img_ptr, coord(center.x - a.y, center.y - a.x), center.x + a.y, color);
	draw_hline(img_ptr, coord(center.x - a.y, center.y + a.x), center.x + a.y, color);
	draw_hline(img_ptr, coord(center.x - a.x, center.y + a.y), center.x + a.x, color);
}

void	draw_fcircle(void *img_ptr, t_coord center, int r, int color)
{
	int x;
	int y;
	int d;

	x = 0;
	y = r;
	d = r - 1;
	while (y >= x)
	{
		fill_square(img_ptr, center, coord(x, y), color);
		if (d >= 2 * x)
			d = d -( 2 * x++) - 1;
		else if ( d < 2 * (r - y))
			d = d + ( 2 * y--) - 1;
		else
			d = d + (2 * (y-- - x++ - 1));
	}
}
