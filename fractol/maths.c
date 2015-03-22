/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 00:41:32 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/14 00:41:34 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	torad(int a)
{
	return ((a * M_PI) / 180);
}

double	modulus(double a, double b)
{
	return (sqrt(a * a + b * b));
}
