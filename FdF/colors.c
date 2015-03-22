/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 01:00:27 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/14 01:00:41 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	assign(t_color *c, size_t c1, size_t c2, size_t c3)
{
	c->r = c1;
	c->g = c2;
	c->b = c3;
}

void	hsvtorgb(t_color *c, size_t h, size_t s, size_t v)
{
	size_t fpart;
	size_t p;
	size_t q;
	size_t t;

	fpart = (h - ((h / 43) * 43)) * 6;
	p = (v * (255 - s)) >> 8;
	q = (v * (255 - ((s * fpart) >> 8))) >> 8;
	t = (v * (255 - ((s * (255 - fpart)) >> 8))) >> 8;
	if (s == 0)
		assign(c, v, v, v);
	else if ((h / 43) == 0)
		assign(c, v, t, p);
	else if ((h / 43) == 1)
		assign(c, q, v, p);
	else if ((h / 43) == 2)
		assign(c, p, v, t);
	else if ((h / 43) == 3)
		assign(c, p, q, v);
	else if ((h / 43) == 4)
		assign(c, t, p, v);
	else
		assign(c, v, p, q);
	c->hexa = c->r * 0x010000 + c->g * 0x000100 + c->b * 0x000001;
}
