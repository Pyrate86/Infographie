/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 11:45:31 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/15 12:44:52 by ghilbert         ###   ########.fr       */
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