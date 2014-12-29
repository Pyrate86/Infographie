/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 11:48:42 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/17 11:48:53 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	skybox(t_env *e)
{
	int x;
	int start;
	int	y;
	int	i;

	start = 0;
	x = e->x;
	if (e->diry < 0.0)
		x += ((e->dirx * 100) + 100) * e->s_w_fact;
	else
		x += e->s_w - ((e->dirx * 100) + 100) * e->s_w_fact;
	while (start <= HEIGHT / 2)
	{
		i = e->x * (e->bpp / 8) + start * e->sl;
		y = x * (e->s_bpp / 8) + start * e->s_sl;
		e->data[i] = e->s_data[y];
		e->data[i + 1] = e->s_data[y + 1];
		e->data[i + 2] = e->s_data[y + 2];
		start++;
	}
}