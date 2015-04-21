/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 11:45:31 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/21 14:46:39 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

int		get_pxl_color(int c)
{
	int color;

	color = c <= 0x7F && c >= 0 ? c : c + 0x100;
	color = color > 255 ? 255 : color;
	return (color);
}

void	swap_coord(t_coord *a, t_coord *b)
{
	t_coord	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_coord	coord(int x, int y)
{
	t_coord ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

t_box	boxing(t_coord a, t_coord b)
{
	t_box	box;

	box.x = a.x;
	box.y = a.y;
	box.w = b.x - a.x;
	box.h = b.y - a.y;
	return (box);
}

t_line	line(t_coord a, t_coord b)
{
	t_line	l;

	l.p1 = a;
	l.p2 = b;
	return (l);
}
