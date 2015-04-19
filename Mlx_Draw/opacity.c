/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opacity.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 19:21:05 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/16 19:52:15 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

static int	get_average(int a, int b, float op)
{
	int ret;

	ret = get_pxl_color(a) * (1.0 - op) + get_pxl_color(b) * op;
	return (ret);
}

static void	put_pixel(t_image *bg, t_image *fg, t_coord loop, float op)
{
	int r;
	int g;
	int b;

	r = get_average(bg->data[loop.x], fg->data[loop.y], op);
	g = get_average(bg->data[loop.x + 1], fg->data[loop.y + 1], op);
	b = get_average(bg->data[loop.x + 2], fg->data[loop.y + 2], op);
	bg->data[loop.x] = r;
	bg->data[loop.x + 1] = g;
	bg->data[loop.x + 2] = b;
}

void		draw_opacity(void *img_bg, t_image *fg, t_coord tl, float op)
{
	t_image *bg;
	int		i;
	int		j;
	int		x;
	int		y;

	bg = (t_image *)malloc(sizeof(t_image));
	bg->data = mlx_get_data_addr(img_bg, &(bg->bpp), &(bg->sl), &(bg->end));
	fg->data = mlx_get_data_addr(fg->img, &(fg->bpp), &(fg->sl), &(fg->end));
	y = 0;
	while (y < fg->h)
	{
		x = 0;
		while (x < fg->w)
		{
			j = x * (fg->bpp / 8) + y * fg->sl;
			i = (tl.x + x) * (bg->bpp / 8) + (tl.y + y) * bg->sl;
			put_pixel(bg, fg, coord(i, j), op);
			x++;
		}
		y++;
	}
}
