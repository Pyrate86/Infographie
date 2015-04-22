/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 15:08:53 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/22 14:58:59 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

static t_image	*new_rt(t_env *e, t_image *img)
{
	t_image *rt;

	rt = (t_image *)malloc(sizeof(t_image));
	rt->img = mlx_new_image(e->mlx, img->w, img->h);
	rt->w = img->w;
	rt->h = img->h;
	rt->data = mlx_get_data_addr(rt->img, &(rt->bpp), &(rt->sl), &(rt->end));
	return (rt);
}

static t_coord	pixel_pos(int angle, t_coord loop, t_coord center)
{
	t_coord	pxl;

	pxl.x = cos(angle * M_PI / 180) * (loop.x - center.x);
	pxl.x = pxl.x - sin(angle * M_PI / 180) * (loop.y - center.y) + center.x;
	pxl.y = sin(angle * M_PI / 180) * (loop.x - center.x);
	pxl.y += cos(angle * M_PI / 180) * (loop.y - center.y) + center.y;
	return (pxl);
}

static void		put_pixel(t_image *rt, t_image *img, t_coord loop, t_coord pxl)
{
	int	i;
	int	j;

	i = (loop.x * (rt->bpp / 8)) + (loop.y * rt->sl);
	j = (pxl.x * (img->bpp / 8)) + (pxl.y * img->sl);
	rt->data[i] = img->data[j];
	rt->data[i + 1] = img->data[j + 1];
	rt->data[i + 2] = img->data[j + 2];
}

static void		put_color_pixel(t_image *rt, t_coord loop, int color)
{
	int	i;

	i = (loop.x * (rt->bpp / 8)) + (loop.y * rt->sl);
	rt->data[i] = color;
	rt->data[i + 1] = color >> 8;
	rt->data[i + 2] = color >> 16;
}

t_image			*rotation(t_env *e, t_image *img, int angle, int color)
{
	t_image	*rt;
	t_coord	loop;
	t_coord pxl;
	t_coord	center;

	rt = new_rt(e, img);
	center = coord(img->w / 2, img->h / 2);
	loop.x = -1;
	while (++loop.x < rt->w)
	{
		loop.y = -1;
		while (++loop.y < rt->h)
		{
			pxl = pixel_pos(angle, loop, center);
			if (pxl.x < img->w && pxl.x > 0 && pxl.y > 0 && pxl.y < img->h)
				put_pixel(rt, img, loop, pxl);
			else
				put_color_pixel(rt, loop, color);
		}
	}
	return (rt);
}
