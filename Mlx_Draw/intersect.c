/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 15:48:26 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/20 23:54:42 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

static int	inter_bb(t_line a, t_line b)
{
	t_box	box_a;
	t_box	box_b;
	t_coord	min;
	t_coord	max;

	min = get_min(a.p1, a.p2);
	max = get_max(a.p1, a.p2);
	box_a = boxing(min, max);
	min = get_min(b.p1, b.p2);
	max = get_max(b.p1, b.p2);
	box_b = boxing(min, max);
	if ((box_b.x > box_a.x + box_a.w)
		|| (box_b.x + box_b.w < box_a.x)
		|| (box_b.y > box_a.y + box_a.h)
		|| (box_b.y + box_b.h < box_a.y))
		return (0);
	return (1);
}

static int	inter_seg(t_line a, t_line b)
{
	t_coord	d;
	t_coord	e;
	double	den;
	double	t;
	double	u;

	d.x = a.p2.x - a.p1.x;
	d.y = a.p2.y - a.p1.y;
	e.x = b.p2.x - b.p1.x;
	e.y = b.p2.y - b.p1.y;
	den = d.x * e.y - d.y * e.x;
	if (den == 0)
		return (-1);
	t = -(a.p1.x * e.y - b.p1.x * e.y - e.x * a.p1.y + e.x * b.p1.y) / den;
	if (t < 0 || t >= 1)
		return (0);
	u = -(-d.x * a.p1.y + d.x * b.p1.y + d.y * a.p1.x - d.y * b.p1.x) / den;
	if (u < 0 || u >= 1)
		return (0);
	return (1);
}

int			intersect(t_line a, t_line b)
{
	if (inter_bb(a, b))
	{
		if (inter_seg(a, b) > 0)
			return (1);
	}
	return (0);
}
