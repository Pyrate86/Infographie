/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 05:44:29 by ghilbert          #+#    #+#             */
/*   Updated: 2015/01/08 05:44:41 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				draw_third(t_complexe *c, t_complexe *z, double iter)
{
	int		i;
	double	tmpx;
	double	tmpy;

	i = 0;
	while (modulus(z->reel, z->imag) < 4 && i < iter)
	{
		tmpx = z->reel * z->reel * z->imag - z->imag * z->imag + c->reel;
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
	frac->zoom = 173;
	frac->x1 = -1.843;
	frac->y1 = -1.869;
	frac->c_r = -0.6;
	frac->c_i = -0.154654;
	frac->z_r = 0;
	frac->z_i = 0;
	frac->x2 = frac->x1 + ((double)WIDTH / (double)frac->zoom);
	frac->y2 = frac->y1 + ((double)HEIGHT / (double)frac->zoom);
	frac->iter_factor = 30;
	frac->m_iter = sqrt(abs(2 * sqrt(abs(1 - sqrt(5 * frac->zoom))))) * 30;
	return (frac);
}

void			thirdloop(t_complexe *c, t_complexe *z, t_coord l, t_frac frac)
{
	c->reel = frac.c_r;
	c->imag = frac.c_i;
	z->reel = l.x / frac.zoom + frac.x1;
	z->imag = l.y / frac.zoom + frac.y1;
}

void			third(t_env *e)
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
	}	loop.x = -1;
	while (++loop.x < WIDTH)
	{
		loop.y = -1;
		while (++loop.y < HEIGHT)
		{
			thirdloop(&c, &z, loop, *e->frac);
			i = draw_third(&c, &z, floor(e->frac->m_iter));
			hsvtorgb(&color, i % 255, 255, 255 * (i < floor(e->frac->m_iter)));
			mlx_pixel_put_img(e->img, loop.x, loop.y, color.hexa);
		}
	}
}
