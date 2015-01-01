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

#include "wolf.h"

void	mlx_pixel_put_img(void *img_ptr, int x, int y, int color)
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

void	swap_coord(t_coord *a, t_coord *b)
{
	t_coord	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	drawline(void *img_ptr, t_coord a, t_coord b, int color)
{
	int	x;
	int	y;
	int div;

	if (a.y < b.y)
		swap_coord(&a, &b);
	y = a.y + 1;
	if ((b.x - a.x) >= (b.y - a.y))
	{
		while (--y >= b.y)
		{
			div = b.y - a.y == 0 ? 1 : b.y - a.y;
			x = a.x + ((b.x - a.x) * (y - a.y)) / div;
			mlx_pixel_put_img(img_ptr, x, y, color);
		}
	}
	if (a.x > b.x)
		swap_coord(&a, &b);
	x = a.x;
	while (++x <= b.x)
	{
		div = b.x - a.x == 0 ? 1 : b.x - a.x;
		y = a.y + ((b.y - a.y) * (x - a.x)) / div;
		mlx_pixel_put_img(img_ptr, x, y, color);
	}
}

void	draw_sqr(void *img_ptr, t_coord a, t_coord b, int color)
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

void	flushscreen(t_env *e)
{
	static void	*img = NULL;

	if (img == NULL)
		img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
