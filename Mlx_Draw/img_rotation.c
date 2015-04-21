/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 15:08:53 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/21 19:09:41 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"
#include <stdio.h>
t_image	*rotation(t_env *e, t_image *img, int angle, int color)
{
	t_image	*res;
	int		x;
	int		y;
	int		x2;
	int		y2;
	float	cosinus;
	float	sinus;
	t_coord	center;
(void)e;

	res = (t_image *)malloc(sizeof(t_image));
	res->img = mlx_new_image(e->mlx, img->w, img->h);
	res->w = img->w;
	res->h = img->h;
	res->data = mlx_get_data_addr(res->img, &(res->bpp), &(res->sl), &(res->end));
	center.x = img->w / 2;
	center.y = img->h / 2;
	cosinus = cos(angle * M_PI / 180);
	sinus = sin(angle * M_PI / 180);
	x= 0;

	while (x < res->w)
	{
		y = 0;
		while (y < res->h)
		{
			x2 = cosinus * (x - center.x) - sinus * (y - center.y) + center.x;
			y2 = sinus * (x - center.x) + cosinus * (y - center.y) + center.y;
			int i = (x  * (res->bpp / 8)) + (y * res->sl);
			if (x2 < img->w && x2 >0 && y2 >0 && y2 < img->h)
			{
				int j = (x2 * (img->bpp / 8)) + (y2 * img->sl);
				res->data[i] = img->data[j];
				res->data[i + 1] = img->data[j + 1];
				res->data[i + 2] = img->data[j + 2];
			}
			else
			{
				res->data[i] = color;
				res->data[i + 1] = color >> 8;
				res->data[i + 2] = color >> 16;
			}
			y++;
		}
		x++;
	}
	return (res);
}
