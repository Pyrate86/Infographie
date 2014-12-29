/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 07:46:20 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/16 07:46:30 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	hit_wall(t_env *e)
{
	if (e->sidedistx < e->sidedisty)
	{
		e->sidedistx += e->deltadistx;
		e->mapx += e->stepx;
		e->side = e->stepx < 0 ? 0 : 1;
	}
	else
	{
		e->sidedisty += e->deltadisty;
		e->mapy += e->stepy;
		e->side = e->stepy < 0 ? 2 : 3;
	}
	if (e->map[e->mapy][e->mapx] != ' ')
		e->hit = 1;
}

void	color_walls(t_env *e)
{

	if (e->side == 1)
		e->color = 0x0000FF;
	else if (e->side == 2)
		e->color = 0x00FF00;
	else if (e->side == 3)
		e->color = 0xFF0000;
	else
		e->color = 0x7F7F7F;
}

void	draw(t_env *e, int start, int end)
{
	int		i;
	int		t_y;
	int		pxl;
	float	d;
	t_coord	tile;

	while (start <= end)
	{
		d = (start + (e->lineheight - HEIGHT) / 2);
		t_y = ((d * TEX_HEIGHT) / e->lineheight);
		if (e->side == 0 || e->side == 3)
			tile.x = ((e->map[e->mapy][e->mapx] - 33) % 10) * 64 - e->t_x + 63;
		else
			tile.x = ((e->map[e->mapy][e->mapx] - 33) % 10) * 64 + e->t_x;
		tile.y = ((e->map[e->mapy][e->mapx] - 33) / 10) * 64 + t_y;
		pxl = tile.x * (e->t_bpp / 8) + tile.y * e->t_sl;
		i = e->x * (e->bpp / 8) + start * e->sl;
		e->data[i] = e->t_data[pxl];
		e->data[i + 1] = e->t_data[pxl + 1];
		e->data[i + 2] = e->t_data[pxl + 2];
		e->data[i + 3] = e->t_data[pxl + 3];
		start++;
	}
}

void	drawcf(t_env *e, int start, int end)
{
	int		i;

	while (start <= end)
	{
		i = e->x * (e->bpp / 8) + start * e->sl;
		e->data[i] = e->color;
		e->data[i + 1] = e->color >> 8;
		e->data[i + 2] = e->color >> 16;
		start++;
	}
}
