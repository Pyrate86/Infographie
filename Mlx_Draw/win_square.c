/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 13:33:37 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/15 13:57:46 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

void	draw_win_square(t_env *e, t_coord a, t_coord b, int color)
{
	draw_win_vline(e, a, b.y, color);
	draw_win_vline(e, b, a.y, color);
	draw_win_hline(e, a, b.x, color);
	draw_win_hline(e, b, a.x, color);
}

void	draw_win_fsquare(t_env *e, t_coord a, t_coord b, int color)
{
	int x;
	int y;

	x = a.x;
	while (x <= b.x)
	{
		y = a.y;
		while (y <= b.y)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, color);
			y++;
		}
		x++;
	}
}
