/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xdraw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 01:15:45 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/15 01:18:39 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			mlx_pixel_put_img(void *img_ptr, int x, int y, int color)
{
	char	*data;
	int		bbp;
	int		sizeline;
	int		endian;
	int		i;

	data = mlx_get_data_addr(img_ptr, &bbp, &sizeline, &endian);
	bbp /= 8;
	i = x * bbp + y * sizeline;
	if (WIDTH * bbp + HEIGHT * sizeline < i)
		return ;
	if (x >= 0 && y >= 0)
	{
		data[i] = color;
		data[i + 1] = color >> 8;
		data[i + 2] = color >> 16;
	}
}

void			swap_coord(t_coord *a, t_coord *b)
{
	t_coord	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

unsigned int	color_from_height(int height)
{
	t_color	color;

	hsvtorgb(&color, 100 - height, 255, 255);
	return (color.hexa);
}

void			draw_sqr(void *img_ptr, t_coord a, t_coord b, int color)
{
	int x;
	int y;

	x = a.x;
	while (x <= b.x)
	{
		y = a.y;
		while (y <= b.y)
		{
			mlx_pixel_put_img(img_ptr, x, y, color);
			y++;
		}
		x++;
	}
}

void			flushscreen(t_env *e)
{
	t_coord a;
	t_coord b;

	a.x = 0;
	a.y = 0;
	b.x = WIDTH;
	b.y = HEIGHT;
	draw_sqr(e->img, a, b, 0);
}
