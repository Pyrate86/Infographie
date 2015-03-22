/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 00:44:17 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/14 00:44:19 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		draw_mand(t_complexe *c, t_complexe *z, double iter)
{
	int		i;
	double	tmpx;
	double	tmpy;

	i = 0;
	while (modulus(z->reel, z->imag) < 4 && i < iter)
	{
		tmpx = z->reel * z->reel - z->imag * z->imag + c->reel;
		tmpy = 2 * z->imag * z->reel + c->imag;
		if (z->reel == tmpx && z->imag == tmpy)
			i = iter;
		else
		{
			z->reel = tmpx;
			z->imag = tmpy;
			i++;
		}
	}
	return (i);
}

static t_frac	*init_fractal(void)
{
	t_frac	*frac;

	frac = (t_frac *)malloc(sizeof(t_frac));
	frac->zoom = 200;
	frac->x1 = -2.1;
	frac->y1 = -1.2;
	frac->c_r = 0;
	frac->c_i = 0;
	frac->z_r = 0;
	frac->z_i = 0;
	frac->x2 = frac->x1 + ((double)WIDTH / (double)frac->zoom);
	frac->y2 = frac->y1 + ((double)HEIGHT / (double)frac->zoom);
	frac->iter_factor = 25;
	frac->m_iter = sqrt(abs(2 * sqrt(abs(1 - sqrt(5 * frac->zoom))))) * 25;
	return (frac);
}

void	mandeloop(t_complexe *c, t_complexe *z, t_coord loop, t_frac frac)
{
	c->reel = loop.x / frac.zoom + frac.x1;
	c->imag = loop.y / frac.zoom + frac.y1;
	z->reel = frac.z_r;
	z->imag = frac.z_i;
}

void	mandelbrot(t_env *e)
{
	t_coord		loop;
	t_complexe	c;
	t_complexe	z;
	t_color		color;
	int			i;

	if (e->init == 0)
	{
		e->frac = init_fractal();
		e->init = 1;
	}
	loop.x = -1;
	while (++loop.x < WIDTH)
	{
		loop.y = -1;
		while (++loop.y < HEIGHT)
		{
			mandeloop(&c, &z, loop, *e->frac);
			i = draw_mand(&c, &z, floor(e->frac->m_iter));
			hsvtorgb(&color, i % 255, 255, 255 * (i < floor(e->frac->m_iter)));
			mlx_pixel_put_img(e->img, loop.x, loop.y, color.hexa);
		}
	}
}
