/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/01 05:37:08 by ghilbert          #+#    #+#             */
/*   Updated: 2015/01/01 05:37:17 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_env *e)
{
	e->tile_size = 50;
	e->interval.x = 0;
	e->interval.y = 0;
	e->getmap = 0;
	e->height = 5;
	e->loading = 0;
}