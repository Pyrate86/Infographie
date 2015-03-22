/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 04:17:41 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/14 04:18:00 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_frac *frac, int x, int y)
{
	double tmpx1;
	double tmpy1;

	tmpx1 = (double)x / (double)frac->zoom + frac->x1;
	tmpy1 = (double)y / (double)frac->zoom + (double)frac->y1;
	frac->zoom *= 1.2;
	frac->x2 = tmpx1 + ((double)WIDTH / (double)frac->zoom);
	frac->y2 = tmpy1 + ((double)HEIGHT / (double)frac->zoom);
	frac->x1 = tmpx1 - ((frac->x2 - tmpx1) / 2);
	frac->y1 = tmpy1 - ((frac->y2 - tmpy1) / 2);
	frac->x2 = tmpx1 + ((frac->x2 - tmpx1) / 2);
	frac->y2 = tmpy1 + ((frac->y2 - tmpy1) / 2);
}

void	unzoom(t_frac *frac, int x, int y)
{
	double tmpx1;
	double tmpy1;

	if (frac->zoom > 50)
		frac->zoom /= 1.2;
	tmpx1 = (double)x / (double)frac->zoom + frac->x1;
	tmpy1 = (double)y / (double)frac->zoom + (double)frac->y1;
	frac->x2 = tmpx1 + ((double)WIDTH / (double)frac->zoom);
	frac->y2 = tmpy1 + ((double)HEIGHT / (double)frac->zoom);
	frac->x1 = tmpx1 - ((frac->x2 - tmpx1) / 2);
	frac->y1 = tmpy1 - ((frac->y2 - tmpy1) / 2);
	frac->x2 = tmpx1 + ((frac->x2 - tmpx1) / 2);
	frac->y2 = tmpy1 + ((frac->y2 - tmpy1) / 2);
}
