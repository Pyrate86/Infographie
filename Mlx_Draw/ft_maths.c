/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 19:27:49 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/20 23:53:09 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

t_coord	get_max(t_coord a, t_coord b)
{
	t_coord max;

	max.x = MAX(a.x, b.x);
	max.y = MAX(a.y, b.y);
	return (max);
}

t_coord	get_min(t_coord a, t_coord b)
{
	t_coord min;

	min.x = MIN(a.x, b.x);
	min.y = MIN(a.y, b.y);
	return (min);
}
