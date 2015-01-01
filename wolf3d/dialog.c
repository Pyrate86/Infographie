/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dialog.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 03:59:31 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/31 03:59:41 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	welcome_dialog(t_env *e)
{
	t_coord	a;
	t_coord	b;
	void	*cursor;

	mlx_put_image_to_window(e->mlx, e->win, e->w_screen, 0, 0);
	a = init_coord(905, 579);
	b = init_coord(1060, 583);
	if (e->w_select == 1)
	{
		a = init_coord(905, 645);
		b = init_coord(1012, 649);
	}
	cursor = mlx_new_image(e->mlx, b.x - a.x, b.y - a.y);
	mlx_put_image_to_window(e->mlx, e->win, cursor, a.x, a.y);
}

void	no_name_1(t_env *e, void *bg_img, void *fg_img)
{
	t_coord	p;
	int		pxl;
	int		i;
	t_img	bg;
	t_img	fg;

	bg.data = mlx_get_data_addr(bg_img, &bg.bpp, &bg.sl, &bg.end);
	fg.data = mlx_get_data_addr(fg_img, &fg.bpp, &fg.sl, &fg.end);
	p.x = 0;
	while (p.x < 896)
	{
		p.y = 0;
		while (p.y < 64)
		{
			pxl = ((p.x + 64) * (bg.bpp / 8));
			pxl += ((p.y + ((e->t_set + 1) * 64)) * bg.sl);
			i = p.x * (fg.bpp / 8) + p.y * fg.sl;
			fg.data[i] = bg.data[pxl] + ((p.x < 32 || p.x > 96) ? 0x7F : 0);
			fg.data[i + 1] = bg.data[pxl + 1];
			fg.data[i + 2] = bg.data[pxl + 2];
			p.y++;
		}
		p.x++;
	}
}

void	tex_dialog(t_env *e)
{
	void	*dialog;
	void	*selec;
	char	*file;

	file = "img/sprite/selector.xpm";
	dialog = mlx_xpm_file_to_image(e->mlx, file, &e->w, &e->h);
	mlx_put_image_to_window(e->mlx, e->win, dialog, 128, 100);
	selec = mlx_new_image(e->mlx, 896, 64);
	no_name_1(e, dialog, selec);
	mlx_put_image_to_window(e->mlx, e->win, selec, 192, 164 + (e->t_set * 64));
}
