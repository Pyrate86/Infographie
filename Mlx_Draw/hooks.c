/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 11:34:01 by ghilbert          #+#    #+#             */
/*   Updated: 2015/06/06 19:58:53 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

static void		redraw(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	draw_win(e);
}

int				key_hook(int k, t_env *e)
{
	if (k == KEY_ESCAPE)
		exit (0);
	redraw(e);
	return (k);
}

int				expose_hook(t_env *e)
{
	redraw(e);
	return (0);
}

#include <stdio.h>

int		mouse_hook(int button, int x, int y, t_env *e)
{
	(void)button;
	(void)x;
	(void)y;
	(void)e;

	// redraw(e);
	return (0);
}

int		mouse_motion(int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	(void)e;

//	redraw(e);
	return (0);
}
