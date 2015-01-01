/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 01:20:58 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/15 01:21:24 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(void)
{
	t_env	e;

	e.mlx = mlx_init();
	if (e.mlx == NULL)
		return (-1);
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT + 200, "Wolf");
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.sl), &(e.endian));
	init_world(&e);
	init_tex(&e);
	init_sprites(&e);
	get_map(&e);
	init_player(&e);
	mlx_hook(e.win, 2, 3, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
