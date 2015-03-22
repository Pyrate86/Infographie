/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 00:40:23 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/15 00:40:42 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, t_env *e)
{
	(void)e;
	if (keycode == 53)
		exit(0);
	if (keycode == 46)
		e->motion = e->motion == 0 ? 1 : 0;
	if (keycode == 34)
		show_infos(e);
	if (keycode == 4)
		show_help(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	t_frac *frac;

	frac = e->frac;
	if (button == 5 || button == 1)
		zoom(frac, x, y);
	if (button == 2 || button == 7)
		unzoom(frac, x, y);
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	frac->m_iter = sqrt(abs(2 * sqrt(abs(1 - sqrt(5 * frac->zoom)))));
	frac->m_iter *= frac->iter_factor;
	draw(e);
	return (0);
}

int		mouse_motion(int x, int y, t_env *e)
{
	t_frac *frac;

	if (e->motion)
	{
		frac = e->frac;
		frac->c_r = ((double)x / (double)frac->zoom + frac->x1) / 2;
		frac->c_i = ((double)y / (double)frac->zoom + (double)frac->y1) / 2;
		frac->z_r = (double)x / (double)frac->zoom + frac->x1;
		frac->z_i = (double)y / (double)frac->zoom + (double)frac->y1;
		e->help = 0;
		mlx_destroy_image(e->mlx, e->img);
		e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
		draw(e);
	}
	return (0);
}

int		expose_hook(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	draw(e);
	return (0);
}
