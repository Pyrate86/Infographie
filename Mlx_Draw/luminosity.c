/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luminosity.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 20:40:05 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/16 22:37:43 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

static int	get_color(int a, float lum)
{
	int ret;

	ret = get_pxl_color(a) * lum;
	return (ret);
}

static void	put_pixel(t_image *bg, t_image *fg, t_coord loop, float lum)
{
	int r;
	int g;
	int b;

	r = get_color(fg->data[loop.y], lum);
	g = get_color(fg->data[loop.y + 1], lum);
	b = get_color(fg->data[loop.y + 2], lum);
	bg->data[loop.x] = r;
	bg->data[loop.x + 1] = g;
	bg->data[loop.x + 2] = b;
}

void		draw_luminosity(void *img_bg, t_image *fg, t_coord t, float l)
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
			i = (t.x + x) * (bg->bpp / 8) + (t.y + y) * bg->sl;
			put_pixel(bg, fg, coord(i, j), l);
			x++;
		}
		y++;
	}
}

static void	set_color(t_image *img, int x, float lum)
{
	img->data[x] = get_color(img->data[x], lum);
	img->data[x + 1] = get_color(img->data[x + 1], lum);
	img->data[x + 2] = get_color(img->data[x + 2], lum);
}

void		set_luminosity(t_image *img, float lum)
{
	int x;
	int y;
	int i;

	y = 0;
	while (y < img->h)
	{
		x = 0;
		while (x < img->w)
		{
			i = x * (img->bpp / 8) + y * img->sl;
			set_color(img, i, lum);
			x++;
		}
		y++;
	}
}
