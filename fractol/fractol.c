/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 05:43:42 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/14 05:43:46 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_env *e)
{
	if (!ft_strcmp(e->file, "julia"))
		julia(e);
	else if (!ft_strcmp(e->file, "third"))
		third(e);
	else
		mandelbrot(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	if (e->info)
	{
		e->info = 0;
		show_infos(e);
	}
	if (e->help)
	{
		e->help = 0;
		show_help(e);
	}
}
