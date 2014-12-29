/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 10:49:03 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/16 07:43:19 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_ray(t_env *e)
{
	e->rayposx = e->posx;
	e->rayposy = e->posy;
	e->camerax = -2 * (double)e->x / (double)WIDTH + 1;
	e->rdirx = e->dirx + e->planx * e->camerax;
	e->rdiry = e->diry + e->plany * e->camerax;
	e->mapx = (int)e->rayposx;
	e->mapy = (int)e->rayposy;
	e->deltadistx = sqrt(1 + (e->rdiry * e->rdiry) / (e->rdirx * e->rdirx));
	e->deltadisty = sqrt(1 + (e->rdirx * e->rdirx) / (e->rdiry * e->rdiry));
	e->hit = 0;
}

void	init_steps(t_env *e)
{
	if (e->rdirx < 0)
	{
		e->stepx = -1;
		e->sidedistx = (e->rayposx - e->mapx) * e->deltadistx;
	}
	else
	{
		e->stepx = 1;
		e->sidedistx = (e->mapx + 1.0 - e->rayposx) * e->deltadistx;
	}
	if (e->rdiry < 0)
	{
		e->stepy = -1;
		e->sidedisty = (e->rayposy - e->mapy) * e->deltadisty;
	}
	else
	{
		e->stepy = 1;
		e->sidedisty = (e->mapy + 1.0 - e->rayposy) * e->deltadisty;
	}
}

void	dda(t_env *e)
{
	double	calc_tmp_x;
	double	calc_tmp_y;

	while (e->hit == 0)
		hit_wall(e);
	calc_tmp_x = (e->mapx - e->rayposx + (1 - e->stepx) / 2);
	calc_tmp_y = (e->mapy - e->rayposy + (1 - e->stepy) / 2);
	if (e->side == 0 || e->side == 1)
		e->wallh = fabs(calc_tmp_x / e->rdirx);
	else
		e->wallh = fabs(calc_tmp_y / e->rdiry);
	if (e->side == 2 || e->side == 3)
		e->t_wallx = e->rayposx + (calc_tmp_y / e->rdiry) * e->rdirx;
	else
		e->t_wallx = e->rayposy + (calc_tmp_x / e->rdirx) * e->rdiry;
	e->t_wallx -= floor(e->t_wallx);
	e->t_x = (int)(e->t_wallx * (double)(TEX_WIDTH));
}

void	height_calc(t_env *e)
{
	int		start;
	int		end;

	e->lineheight = ABS((int)(HEIGHT / e->wallh));
	start = (HEIGHT / 2) - (e->lineheight / 2);
	if (start < 0)
		start = 0;
	end = (HEIGHT / 2) + (e->lineheight / 2);
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	color_walls(e);
	if (e->textured)
		draw(e, start, end);
	else
		drawcf(e, start, end);
}

void	raycasting(t_env *e)
{
	e->x = 0;
	while (e->x < WIDTH)
	{
		init_ray(e);
		init_steps(e);
		if (e->textured)
			skybox(e);
		init_ray(e);
		init_steps(e);
		dda(e);
		height_calc(e);
		if (e->textured)
			draw_floor(e);
		e->x++;
	}
}
