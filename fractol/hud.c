/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 04:36:08 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/14 04:36:14 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		show_percent(t_env *e, int x)
{
	int	color;

	color = 0xFFFFFF;
	mlx_pixel_put(e->mlx, e->win, x, 0, color);
	mlx_pixel_put(e->mlx, e->win, x, 3, color);
	mlx_pixel_put(e->mlx, e->win, x + 1, 0, color);
	mlx_pixel_put(e->mlx, e->win, x + 1, 3, color);
	mlx_pixel_put(e->mlx, e->win, x + 1, 1, color);
	mlx_pixel_put(e->mlx, e->win, x + 1, 2, color);
	if (x > 0)
		color = 0x046380;
	mlx_pixel_put(e->mlx, e->win, x, 1, color);
	mlx_pixel_put(e->mlx, e->win, x, 2, color);
}

static void	write_help(t_env *e, t_coord a)
{
	char	*m;
	char	*m2;

	m = "M : Changement des parametres";
	m2 = "    a l'aide le la sourie";
	mlx_string_put(e->mlx, e->win, a.x + 2, a.y, 0, "Touches");
	mlx_string_put(e->mlx, e->win, a.x + 2, a.y + 15, 0, "H : Aide");
	mlx_string_put(e->mlx, e->win, a.x + 2, a.y + 30, 0, "I : Infos");
	mlx_string_put(e->mlx, e->win, a.x + 2, a.y + 45, 0, m);
	mlx_string_put(e->mlx, e->win, a.x + 2, a.y + 60, 0, m2);
}

void		show_help(t_env *e)
{
	t_coord a;
	t_coord b;

	if (e->help == 0)
	{
		a.x = WIDTH - (300);
		a.y = HEIGHT - 85;
		b.x = WIDTH - 4;
		b.y = HEIGHT - 4;
		draw_sqr_to_win(e, a, b, 0x0);
		a.x += 1;
		a.y += 1;
		b.x -= 1;
		b.y -= 1;
		draw_sqr_to_win(e, a, b, 0xFFFFFF);
		e->help = 1;
		write_help(e, a);
	}
	else
	{
		e->help = 0;
		draw(e);
	}
}

static void	write_infos(t_env *e, t_coord b, int size)
{
	t_coord a;

	b.x = size < b.x ? b.x : size;
	a.x = 4;
	a.y = 4;
	b.y = 52;
	b.x = b.x * 10 + 10;
	draw_sqr_to_win(e, a, b, 0xFFFFFF);
	a.x += 1;
	a.y += 1;
	b.x -= 1;
	b.y -= 1;
	draw_sqr_to_win(e, a, b, 0x0);
	e->info = 1;
}

void		show_infos(t_env *e)
{
	t_coord b;
	char	zoom[50];
	char	*iter;
	char	equ[50];

	if (e->info == 0)
	{
		sprintf(zoom, "Zoom : %.f", e->frac->zoom);
		iter = ft_strjoin("Iterations : ", ft_itoa(e->frac->m_iter));
		b.x = ft_strlen(iter);
		if (e->frac->y1 > 0)
			sprintf(equ, "C = %.4f + %.4fi", e->frac->x1, e->frac->y1);
		else
			sprintf(equ, "C = %.4f - %.4fi", e->frac->x1, ABS(e->frac->y1));
		b.x = ft_strlen(equ) < (size_t)b.x ? (size_t)b.x : ft_strlen(equ);
		write_infos(e, b, ft_strlen(zoom));
		mlx_string_put(e->mlx, e->win, 7, 2, 0xFFFFFF, zoom);
		mlx_string_put(e->mlx, e->win, 7, 17, 0xFFFFFF, iter);
		mlx_string_put(e->mlx, e->win, 7, 32, 0xFFFFFF, equ);
	}
	else
	{
		e->info = 0;
		draw(e);
	}
}
