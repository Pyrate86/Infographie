/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 11:45:31 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/19 22:33:39 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

void		swap_coord(t_coord *a, t_coord *b)
{
	t_coord	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_coord		coord(int x, int y)
{
	t_coord ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

int			get_pxl_color(int c)
{
	int color;

	color = c <= 0x7F && c >= 0 ? c : c + 0x100;
	color = color > 255 ? 255 : color;
	return (color);
}

t_coord		*intersect(t_line l1, t_line l2)
{
	int		xi;
	int		yi;
	int		d;
	t_coord	*p;

	p = (t_coord *)malloc(sizeof(t_coord));
	d = (l1.p1.x - l1.p2.x) * (l2.p1.y - l2.p2.y) \
		- (l1.p1.y - l1.p2.y) * (l2.p1.x - l2.p2.x);
	if (d == 0)
		return (NULL);
	xi = ((l2.p1.x - l2.p2.x) * (l1.p1.x * l1.p2.y - l1.p1.y * l1.p2.x) \
		- (l1.p1.x - l1.p2.x) * (l2.p1.x * l2.p2.y - l2.p1.y * l2.p2.x)) / d;
	yi = ((l2.p1.y - l2.p2.y) * (l1.p1.x * l1.p2.y - l1.p1.y * l1.p2.x) \
		- (l1.p1.y - l1.p2.y) * (l2.p1.x * l2.p2.y - l2.p1.y * l2.p2.x)) / d;
	p->x = xi;
	p->y = yi;
	if (xi < min(l1.p1.x, l1.p2.x) || xi > max(l1.p1.x, l1.p2.x))
		return (NULL);
	if (xi < min(l2.p1.x, l2.p2.x) || xi > max(l2.p1.x, l2.p2.x))
		return (NULL);
	return (p);
}
