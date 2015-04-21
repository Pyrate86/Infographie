/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 16:44:14 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/21 16:52:22 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

void	draw_image(void *img_bg, t_image *fg, t_coord t)
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
			i = (t.x + x) * (bg->bpp / 8) + (t.y + y) * bg->sl;
			bg->data[i] = fg->data[j];
			bg->data[i + 1] = fg->data[j + 1];
			bg->data[i + 2] = fg->data[j + 2];
			x++;
		}
		y++;
	}
}