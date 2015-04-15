/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 14:28:24 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/15 14:36:52 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

void	draw_win_line(t_env *e, t_coord a, t_coord b, int color)
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
			mlx_pixel_put(e->mlx, e->win, x, y, color);
		}
	}
	if (a.x > b.x)
		swap_coord(&a, &b);
	x = a.x;
	while (++x <= b.x)
	{
		div = b.x - a.x == 0 ? 1 : b.x - a.x;
		y = a.y + ((b.y - a.y) * (x - a.x)) / div;
		mlx_pixel_put(e->mlx, e->win, x, y, color);
	}
}

void	draw_win_hline(t_env *e, t_coord a, int w, int color)
{
	t_coord b;

	b.x = w;
	b.y = a.y;
	draw_win_line(e, a, b, color);
}

void	draw_win_vline(t_env *e, t_coord a, int w, int color)
{
	t_coord b;

	b.y = w;
	b.x = a.x;
	draw_win_line(e, a, b, color);
}
