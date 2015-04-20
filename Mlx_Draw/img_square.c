/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 13:27:48 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/20 17:15:11 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

void	draw_fsquare(void *img_ptr, t_coord a, t_coord b, int color)
{
	int x;
	int y;

	x = a.x;
	while (x <= b.x)
	{
		y = a.y;
		while (y <= b.y)
		{
			draw_pixel(img_ptr, x, y, color);
			y++;
		}
		x++;
	}
}

void	draw_square(void *img_ptr, t_coord a, t_coord b, int color)
{
	draw_vline(img_ptr, a, b.y, color);
	draw_vline(img_ptr, b, a.y, color);
	draw_hline(img_ptr, a, b.x, color);
	draw_hline(img_ptr, b, a.x, color);
}
