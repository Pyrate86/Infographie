/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mask.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 16:34:38 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/16 19:18:56 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

static void	put_pixel(t_image *bg, t_image *fg, t_coord loop, int c)
{
	int tmp;

	tmp = get_pxl_color(fg->data[loop.y]);
	tmp += get_pxl_color(fg->data[loop.y + 1]) * 0x100;
	tmp += get_pxl_color(fg->data[loop.y + 2]) * 0x10000;
	if (tmp != c)
	{
		bg->data[loop.x] = fg->data[loop.y];
		bg->data[loop.x + 1] = fg->data[loop.y + 1];
		bg->data[loop.x + 2] = fg->data[loop.y + 2];
	}
}

void		draw_aplha_mask(void *img_bg, t_image *fg, t_coord tl, int c)
{
	t_image *bg;
	int		i;
	int		j;
	int		x;
	int		y;

	bg = (t_image *)malloc(sizeof(t_image));
	bg->data = mlx_get_data_addr(img_bg, &(bg->bpp), &(bg->sl), &(bg->end));
	fg->data = mlx_get_data_addr(fg->img, &(fg->bpp), &(fg->sl), &(fg->end));
	y = 0;
	while (y < fg->h)
	{
		x = 0;
		while (x < fg->w)
		{
			j = x * (fg->bpp / 8) + y * fg->sl;
			i = (tl.x + x) * (bg->bpp / 8) + (tl.y + y) * bg->sl;
			put_pixel(bg, fg, coord(i, j), c);
			x++;
		}
		y++;
	}
}
