/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xdraw2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 06:36:36 by ghilbert          #+#    #+#             */
/*   Updated: 2015/01/13 06:36:45 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	sans_titre_1(void *img_ptr, t_coord a, t_coord b, int color)
{
	int				x;
	int				y;
	int				div;

	y = (a.y + 1) > HEIGHT ? HEIGHT : a.y + 1;
	while (--y >= b.y)
	{
		div = b.y - a.y == 0 ? 1 : b.y - a.y;
		x = a.x + ((b.x - a.x) * (y - a.y)) / div;
		if (x < WIDTH)
			mlx_pixel_put_img(img_ptr, x, y, color);
	}
}

void		drawline(void *img_ptr, t_coord a, t_coord b, int height)
{
	int	x;
	int	y;
	int	div;
	int	color;

	color = color_from_height(height);
	if (a.y < b.y)
		swap_coord(&a, &b);
	if ((b.x - a.x) >= (b.y - a.y))
		sans_titre_1(img_ptr, a, b, color);
	if (a.x > b.x)
		swap_coord(&a, &b);
	x = a.x;
	while (++x < (b.x > WIDTH ? WIDTH : b.x))
	{
		div = b.x - a.x == 0 ? 1 : b.x - a.x;
		y = a.y + ((b.y - a.y) * (x - a.x)) / div;
		if (y < HEIGHT)
			mlx_pixel_put_img(img_ptr, x, y, color);
	}
}
