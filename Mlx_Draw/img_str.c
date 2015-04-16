/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 15:24:42 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/16 12:03:34 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

void	init_str(t_env *e)
{
	int width, height;

	e->img_font = mlx_xpm_file_to_image (e->mlx,"./includes/font.xpm", &width, &height );
}

static void	draw_char(t_env *e, t_coord a, int color, char c)
{
	t_image *font;
	int x;
	int y;
	int i;
	int pxl;

	font = (t_image *)malloc(sizeof(t_image));
	font->data = mlx_get_data_addr(e->img_font, &(font->bpp), &(font->sl), &(font->end));
	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 20)
		{
			pxl = (x + (c - 32) * 12) * (font->bpp / 8) + y * font->sl;
			i = (a.x + x) * (e->bpp / 8) + (a.y + y) * e->sl;
			if (font->data[pxl] != 0)
			{
				e->data[i] = color % 0x100;
				e->data[i + 1] = color % 0x10000 / 0x100;
				e->data[i + 2] = color / 0x10000;
			}
			y++;
		}
		x++;
	}
}

void	mlx_string_put_img(t_env *e, t_coord a, int color, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 32)
			draw_char(e, coord(a.x + (i * 10), a.y), color, str[i]);
		i++;
	}
}
