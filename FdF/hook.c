/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 03:30:32 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/15 03:30:43 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	z(int k, t_env *e)
{
	if (k == 125)
		e->height = e->height >= 39 ? 39 : e->height + 1;
	else if (k == 126)
		e->height = e->height <= 2 ? 2 : e->height - 1;
}

static void	smooth_zoom(int k, t_env *e)
{
	int	step;

	if ((e->tile_size - 10 < 10 && (k == 78 || k == 123))
		|| (e->tile_size + 1 <= 10 && (k == 69 || k == 124)))
		step = 1;
	else
		step = 10;
	if (k == 78 || k == 123)
	{
		if (e->tile_size > 1)
			e->tile_size -= step;
	}
	else if (k == 69 || k == 124)
		e->tile_size += step;
}

int			key_hook(int k, t_env *e)
{
	if (k == 53)
		exit(0);
	else if (k == 0)
		e->interval.x += 10;
	else if (k == 13)
		e->interval.y += 10;
	else if (k == 2)
		e->interval.x -= 10;
	else if (k == 1)
		e->interval.y -= 10;
	else if (k == 78 || k == 123 || k == 69 || k == 124)
		smooth_zoom(k, e);
	else if (k == 125 || k == 126)
		z(k, e);
	flushscreen(e);
	fdf(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (k);
}

int			expose_hook(t_env *e)
{
	flushscreen(e);
	fdf(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
