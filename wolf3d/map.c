/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 03:49:46 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/15 03:49:50 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		wall_color(t_env *e, int x, int y)
{
	int	color;

	if (e->map[x][y] == 32)
		color = 0xACACAC;
	else if (e->map[x][y] == 33)
		color = 0x505050;
	else if (e->map[x][y] == 34)
		color = 0x7F0000;
	else if (e->map[x][y] == 35)
		color = 0x007F00;
	else if (e->map[x][y] == 36)
		color = 0x00007F;
	else if (e->map[x][y] == 37)
		color = 0x7F7F00;
	else if (e->map[x][y] == 38)
		color = 0x007F7F;
	else if (e->map[x][y] == 39)
		color = 0x7F007F;
	else if (e->map[x][y] == 40)
		color = 0x805030;
	else
		color = 0x202020;
	return (color);
}

void	draw_map(t_env *e)
{
	int		x;
	int		y;
	t_coord a;
	t_coord	b;

	x = 0;
	while (e->map[x])
	{
		y = 0;
		while (e->map[x][y] != '\0')
		{
			a.y = x * 12;
			a.x = y * 12;
			b.y = (x + 1) * 12;
			b.x = (y + 1) * 12;
			draw_sqr(e->img, a, b, wall_color(e, x, y));
			y++;
		}
		x++;
	}
	a.x = (e->posx * 12) - 1;
	a.y = (e->posy * 12) - 1;
	b.x = (e->posx * 12) + 1;
	b.y = (e->posy * 12) + 1;
	draw_sqr(e->img, a, b, 0xFF0000);
}
