/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affich.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 06:47:04 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/31 06:47:15 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	play(t_env *e)
{
	if (e->welcome == 1)
		welcome_dialog(e);
	else if (e->t_select == 1)
		tex_dialog(e);
	else
	{
		draw_bg(e);
		raycasting(e);
		if (e->showmap == 1)
			draw_map(e);
		mlx_put_image_to_window(e->mlx, e->win, e->hud_img, 0, 600);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_put_image_to_window(e->mlx, e->win, e->weapon, 512, 344);
	}
}
